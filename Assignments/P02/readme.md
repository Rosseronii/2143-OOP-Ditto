
## Class Card


Description

	Represents values of cards

Data:

	Rank - (where it ranks in the deck)
	Value - (how much its worth for game X)

Methods:

	SetRank()
	SetValue()
	GetRank()
	GetValue()
	Print()
## Class Deck

Description:

	A container of cards.
	
Data:

	Size - how many cards in deck
	Remaining - how many cards left
Methods:

	Deal - remove a card from the deck
	Shuffle - re-arrange the cards in some random fashion
	Reset - go back to initial state with all cards
	
## Class Hand

Description:

	A container of cards
	
Data:

	Size - how many cards in deck
	Remaining - how many cards left

Methods:

	Shuffle - re-arrange the cards in some random fashion
	Sort - put cards in some order
	Discard - remove a card (based on some choice, not randomly like deal a card)

## Class Player

Description:

	Represents a single player as part of (in this case) a Black Jack game.
Data:

	Name - some identifier
	Hand - instance of a card container class

Methods:

	Bet - remove money from bank.
	Win - add money to bank.
	Hit - add a card to hand.
## Class Bank
Description:

	Represents the bank for the player. Able to add winning bets to players bank or remove losing bets.
Data:

	Amount - current player cash
	
Methods:

	Lose() - remove players bet on loss
	Award() - give player winning amount
	
## Class Dealer

Description:

	Represents the house and is in charge of card management for themself and the player.
	When the dealer deals.
	When the dealer hits.
	When the dealer awards winnings
	Who gets the next card.
	
Methods:

	Win - money gets sucked into the house's vault
	Hit - add a card to hand.
	Deal - deal card to the next player
	
	
## Class Game

Description:

	In charge of the black jack game.
	

Data:

	Players - Vector of player classes
	Dealer - Dealer class

Methods:

	Print - prints current state to console
	AcceptBets - accept all player bets of certain value
	DealRound - start round off

![Alt Text](https://github.com/Rosseronii/2143-OOP-Ditto/blob/master/Assignments/P02/blackjack%20(1).pdf)
