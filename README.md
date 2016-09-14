##Rock, Paper, Scissors &lt;Lizard, Spock>
rpsls in various languages, using various, different approaches.

Over Summer 2016 I set myself the task of learning some different programming langauges.  Having had experience in PHP/mySQL and actionScript 2 and 3, I decided to learn Python.  I quickly got to the point where I was confident in Python, so took on the task of learning C.  This repository is full of my experiments programming Rock, Paper, Scissors or Rock, Paper, Scissors, Lizard, Spock.  I'm still learning C so my approach and syntax, especially with pointers and character arrays, might be poor -I'm working on it! :)

I'll probably add versions in other languages such as Ruby, Java, etc. as I experiment with them.

###Rock, Paper, Scissors Logic

There is only one winning move and one losing move for any given play.  So if we assign the player and computer moves different integers, we can use some maths to work out the winner, thus...

    pr = 1      cr = 3
    pp = 2      pp = 2
    ps = 3      cs = 1
    
A draw would sum to 4, always:

    pr cr:	1,3		pr + cr = 4
    pp cp:	2,2		pp + cp = 4
    ps cs:	3,1		ps + cs = 4
    
A Computer win will sum to in either 3 or 6:

    pr cp	1,2		rock < paper      wraps
    pp cs	2,1		paper < scissors  cuts
    ps cr	3,3		scissors < rock   blunts

A Player win will sum to either 2 or 5:

    pr cs	1,1		rock > scissors		blunts
    pp cr	2,3		paper > rock		wraps
    ps cp	3,2		scissors > paper	cuts

This is easy to implement using `switch` as we only have five numbers to `case`

However we could also do this (11 is a prime number)...

    Outcome = 11 % (11 % (playermove + computer move))
    
That way, a draw would equal 2, a Computer win would equal 1 and a Player win would equal 0. Reducing our `case` to three possibilities.  We could then just use an `if` `else` statement.  N.B. I'm no mathematician so there probably is an easier way of doing this.

###Rock, Paper, Scissors, Lizard, Spock Logic

It's easy when it come to rps as there is only one winning and one losing option based on any one move.  However, when it comes to Rock, Paper, Scissors, Lizard, Spock things get a bit more complex.  There are now two winning and to losing moves based on a given move. So the maths used for Rock, Paper, Scissors no longer works.

So assuming the player is p and the computer is c, we can describe the moves, thus with rock(r), paper(p), scissors(s), lizard(l) and spock(v)...

    pr = 1		cr = 1
    pp = 2		cp = 2
    ps = 3		cs = 3
    pl = 4		cl = 4
    pv = 5		cv = 5

A draw would result in a equivalent

    pr cr:	1,1		rock == rock
    pp cp:	2,2		paper == paper
    ps cs:	3,3		scissors == scissors
    pl cl:	4,4		lizard == lizard
    pv cv:	5,5		spock == spock
    draws = {11,22,33,44,55}

A Computer win can be described as...

    pr cv	1,5		rock < spock      vaporises
    pr cp	1,2		rock < paper      wraps
    pp cl	2,4		paper < lizard    eats
    pp cs	2,3		paper < scissors  cuts
    ps cv	3,5		scissors < spock  smashes
    ps cr	3,1		scissors < rock   blunts
    pl cs	4,3		lizard < scissors decapitates
    pl cr	4,1		lizard < rock     crushes
    pv cl	5,4		spock < lizard    poisons
    pv cp	5,2		spock < paper     disproves
    lose = {12,15,23,24,31,35,41,43,52,54}

A Player win can be described as...

    pr cl	1,4		rock > lizard		crushes
    pr cs	1,3		rock > scissors		blunts
    pp cv	2,5		paper > spock		disproves
    pp cr	2,1		paper > rock		wraps
    ps cl	3,4		scissors > lizard	decapitates
    ps cp	3,2		scissors > paper	cuts
    pl cv	4,5		lizard > spock		poisons
    pl cp	4,2		lizard > paper		eats
    pv cs	5,3		spock > scissors	smashes
    pv cr	5,1		spock > rock		vaporises
    win = {13,14,21,25,32,34,42,45,51,53}

###The C Version
In the C version I have taken this approach.  The player moves is multiplied by ten and added to the computer move resulting in a unique two digit number, this is then compared to two integer arrays for a match.
