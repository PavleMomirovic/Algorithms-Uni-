
/*
An object of class card represents one of the 52 cards in a
standard deck of playing cards.  Each card has a suit and
a value.
Source: https://math.hws.edu/eck/cs124/javanotes4/c5/ex-5-5-answer.html
 */


public class Card {

	public final static int SPADES = 0,       // Codes for the 4 suits.
			HEARTS = 1,
			DIAMONDS = 2,
			CLUBS = 3;

	public final static int ACE = 1,          // Codes for the non-numeric cards.
			JACK = 11,        //   Cards 2 through 10 have their 
			QUEEN = 12,       //   numerical values for their codes.
			KING = 13;

	private final int suit;   // The suit of this card, one of the constants
	//    SPADES, HEARTS, DIAMONDS, CLUBS.

	private final int value;  // The value of this card, from 1 to 13.

	public Card(int theValue, int theSuit) {
		// Construct a card with the specified value and suit.
		// Value must be between 1 and 13.  Suit must be between
		// 0 and 3.  If the parameters are outside these ranges,
		// the constructed card object will be invalid.
		value = theValue;
		suit = theSuit;
	}

	public int getSuit() {
		// Return the int that codes for this card's suit.
		return suit;
	}

	public int getValue() {
		// Return the int that codes for this card's value.
		return value;
	}

	public String getSuitAsString() {
		// Return a String representing the card's suit.
		// (If the card's suit is invalid, "??" is returned.)
		
		// https://unicode-table.com/en/sets/suits-of-the-cards/
		
		switch ( suit ) {
		case SPADES:   return "♠";
		case HEARTS:   return "♥";
		case DIAMONDS: return "♦";
		case CLUBS:    return "♣";
		default:       return "¯\\_(ツ)_/¯";
		}
	}

	public String getValueAsString() {
		// Return a String representing the card's value.
		// If the card's value is invalid, "??" is returned.
		switch ( value ) {
		case 1:   return "A";
		case 2:   return "2";
		case 3:   return "3";
		case 4:   return "4";
		case 5:   return "5";
		case 6:   return "6";
		case 7:   return "7";
		case 8:   return "8";
		case 9:   return "9";
		case 10:  return "10";
		case 11:  return "J";
		case 12:  return "Q";
		case 13:  return "K";
		default:  return "¯\\_(ツ)_/¯";
		}
	}

	public String toString() {
		// Return a String representation of this card, such as
		// "10 of Hearts" or "Queen of Spades".
		return getValueAsString() + "" + getSuitAsString();
	}


} // end class Card