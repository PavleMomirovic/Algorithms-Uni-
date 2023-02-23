import java.util.ArrayList;
import java.util.List;

public class BlackJack {

    private Deck deck;
    private ArrayList<Card> playerCards;
    private ArrayList<Card> dealerCards;
    private ArrayList<Integer> playerBalance;
    public BlackJack(Deck _deck)
    {
        deck = _deck;
        playerBalance = new ArrayList<Integer>();
    }
    public int PlayerSum()
    {
        int sum = 0;
        for(Card card : playerCards)
        {
            sum += card.getValue();
        }
        return sum;
    }
    public int DealerSum()
    {
        int sum = 0;
        for(Card card : dealerCards)
        {
            sum += card.getValue();
        }
        return sum;
    }

    public int BlackJackRecursively()
    {
        playerCards = new ArrayList<Card>();
        dealerCards = new ArrayList<Card>();
        //not enough cards
        if(deck.cardsLeft() < 4) return 0;

        //cards taken
        for(int i = 0 ; i < deck.cardsLeft(); i++)
        {
            playerCards.add(deck.dealCard());
            playerCards.add(deck.dealCard());

            int player = this.PlayerSum();
            int dealer = 0;
            if(player > 21)//fail
            {
                this.playerBalance.add(-1);
                this.playerBalance.add(BlackJackRecursively());
                break;
            }
            for(int j = 0 ; j < deck.cardsLeft() ; j++)
            {
                dealer = DealerSum();
                if(dealer >= 17) break;
                this.dealerCards.add(deck.dealCard());
            }
            if(dealer > 21) dealer = 0;

            playerBalance.add(CMP(player, dealer));
            playerBalance.add(BlackJackRecursively());
        }

        return MAX();
    }

    private int CMP(int playerCards, int dealerCards)
    {
        if(playerCards > dealerCards) return 1;
        else if(playerCards < dealerCards) return -1;
        else return 0;
    }
    private int MAX()
    {
        int balance = 0;
        for(Integer i : this.playerBalance)
        {
            balance += i;
        }
        return balance;
    }
    public void start()
    {


        int result = BlackJackRecursively();

        System.out.println("Players balance: " + result);
    }
}
