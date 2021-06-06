// Poker.cpp : This file contains the 'main' function. Program execution begins and ends there.
// one of the challenges in a platform

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int MAX_CARD_COUNT = 4;

enum class Result { Win, Loss, Tie };
enum class Rank
{
    HIGH_CARD = 1,
    ONE_PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH
};

class Card
{
public:

    Card(char* cardStr)
    {
        m_suit = cardStr[1];
        m_val = setValue(cardStr[0]);
    }

    bool isLessThan(const Card& other)
    {
        return this->m_val < other.m_val;
    }

    int getValue() const
    {
        return m_val;
    }

    char getSuit() const
    {
        return m_suit;
    }
private:

    int setValue(char c)
    {
        int value = '0';
        switch (c) {
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            value = c - '0';
            break;
        case 'T':
            value = 10;
            break;
        case 'J':
            value = 11;
            break;
        case 'Q':
            value = 12;
            break;
        case 'K':
            value = 13;
            break;
        case 'A':
            value = 14;
            break;
        default:
            throw "Unexpected card number";
        }

        return value;
    }

    char m_suit;
    int m_val;

};

struct PokerHand 
{
    PokerHand(const char* pokerhand) 
    {
        if (strlen(pokerhand) == 0)
            throw "Invalid poker hand";

        m_cards.reserve(MAX_CARD_COUNT);

        auto pokerhandTmp = _strdup(pokerhand);

        char* next_token = nullptr;
        auto token = strtok_s(pokerhandTmp, " ", &next_token);
        while (token) 
        {
            m_cards.push_back(Card(token));
            token = strtok_s(nullptr, " ", &next_token);
        }

        std::sort(m_cards.begin(), m_cards.end(), 
            [&](Card& a, Card& b) 
            {
                return a.isLessThan(b);
            });

        free(pokerhandTmp);

        for (size_t i = 0; i < m_cards.size(); i++)
        {
            m_valueTable[m_cards[i].getValue()].push_back(m_cards[i]);
        }

    }

    Result compareWith(const PokerHand& other) const
    {
        Rank rankThis = this->getHandRank();
        Rank rankOther = other.getHandRank();
        
        if (rankThis > rankOther) 
        {
            return Result::Win;
        }
        else if (rankThis < rankOther) 
        {
            return Result::Loss;
        }
        else 
        {
            switch (rankThis)
            {
            case Rank::TWO_PAIR:
            {
                std::vector<int> currValues;
                for (auto it = m_valueTable.begin(); it != m_valueTable.end(); ++it) 
                {
                    currValues.push_back(it->first);
                }

                std::vector<int> otherValues;
                for (auto it = other.getValueTable().begin(); it != other.getValueTable().end(); ++it)
                {
                    otherValues.push_back(it->first);
                }

                sort(currValues.begin(), currValues.end(), std::greater<int>());
                sort(otherValues.begin(), otherValues.end(), std::greater<int>());

                int index = currValues.size() - 1;
                while (index >= 0) 
                {
                    if (currValues[index] > otherValues[index]) 
                    {
                        return Result::Win;
                    }
                    else if (currValues[index] < otherValues[index])
                    {
                        return Result::Loss;
                    }
                    index--;
                }

                return Result::Tie;
                
                break;

            }
            
            case Rank::ONE_PAIR:
            {
                int cardValCurr = 0;
                vector<Card> currCards;
                for (auto& item : m_valueTable)
                {
                    if (item.second.size() == 1)
                    {
                        currCards.insert(currCards.end(), item.second.begin(), item.second.end());
                    }
                    else
                        cardValCurr = item.first;

                }

                int cardValOther = 0;
                vector<Card> otherCards;
                for (auto& item : other.getValueTable())
                {
                    if (item.second.size() == 1)
                    {
                        otherCards.insert(otherCards.end(), item.second.begin(), item.second.end());
                    }
                    else
                        cardValOther = item.first;

                }

                if (cardValCurr > cardValOther)
                    return Result::Win;
                else if (cardValOther > cardValCurr)
                    return Result::Loss;
                else
                {
                    return HighCardCompare(currCards, otherCards);
                }

                break;
            }


            case Rank::HIGH_CARD:
            case Rank::THREE_OF_A_KIND:
            case Rank::STRAIGHT:
            case Rank::FLUSH:
            case Rank::FULL_HOUSE:
            case Rank::FOUR_OF_A_KIND:
            case Rank::STRAIGHT_FLUSH:

                return HighCardCompare(m_cards, other.getCards());
            
            }
        }
    }

    vector<Card> getCards() const
    {
        return m_cards;
    }

    Rank getHandRank() const
    {
        // Let's check each condition
        if (isStraight() && isFlush())
        {
            return Rank::STRAIGHT_FLUSH;
        }

        else if (isFourOfAKind())
        {
            return Rank::FOUR_OF_A_KIND;
        }

        else if (isThreeOfAKind() && isOnePair())
        {
            return Rank::FULL_HOUSE;
        }

        else if (isFlush())
        {
            return Rank::FLUSH;
        }

        else if (isStraight())
        {
            return Rank::STRAIGHT;
        }

        else if (isThreeOfAKind())
        {
            return Rank::THREE_OF_A_KIND;
        }

        else if (isTwoPair())
        {
            return Rank::TWO_PAIR;
        }

        else if (isOnePair())
        {
            return Rank::ONE_PAIR;
        }

        else
        {
            return Rank::HIGH_CARD;
        }
    }

    unordered_map<int, vector<Card>> getValueTable() const
    {
        return m_valueTable;
    }

private:


    bool isStraight() const
    {
        int idx = 0;
        int end = m_cards.size() - 1;

        // ace high and low
        if (m_cards[idx].getValue() == 14)
        {
            ++idx;
        }
        else if ((m_cards[end].getValue() == 14))
        {
            --end;
        }

        for (; idx < end; idx++)
        {
            if (abs(m_cards[idx].getValue() - m_cards[idx + 1].getValue()) != 1)
            {
                return false;
            }
        }

        return true;

    }

    bool isFlush() const
    {
        unordered_set<char> suits;
        for (auto& card : m_cards)
        {
            suits.insert(card.getSuit());
        }

        return suits.size() == 1 ? true : false;
    }

    bool isFourOfAKind() const
    {
        for (auto &item : m_valueTable)
        {
            if (item.second.size() == 4)
                return true;
        }

        return false;
    }

    bool isThreeOfAKind() const
    {
        for (auto& item : m_valueTable)
        {
            if (item.second.size() == 3)
                return true;
        }

        return false;
    }

    bool isTwoPair() const
    {
        bool isFound = false;
        for (auto& item : m_valueTable)
        {
            if (item.second.size() == 2)
            {
                if (!isFound)
                    isFound = true;

                else
                    return true;
            }

        }

        return false;
    }

    bool isOnePair() const
    {
        bool isFound = false;
        for (auto& item : m_valueTable)
        {
            if (item.second.size() == 2)
            {
                return true;
            }

        }

        return false;
    }

    Result HighCardCompare(const vector<Card>& firstCards, const vector<Card>& secondCards) const
    {
        for (int i = firstCards.size() - 1; i >= 0; --i)
        {
            if (firstCards[i].getValue() > secondCards[i].getValue())
            {
                return Result::Win;
            }
            else if (firstCards[i].getValue() < secondCards[i].getValue())
            {
                return Result::Loss;
            }
        }
        return Result::Tie;
    }

    vector<Card> m_cards;

    unordered_map<int, vector<Card>> m_valueTable;
    //unordered_map<int, vector<Card>> m_valueCards;


};


Result compare(const PokerHand& player, const PokerHand& opponent) 
{
    return player.compareWith(opponent);
}




int main()
{
    Result res = compare(PokerHand("6S AD 7H 4S AS"), PokerHand("AH AC 5H 6H 7S"));
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
