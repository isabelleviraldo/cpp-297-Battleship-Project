# cpp-297-Battleship-Project
my code as I advance my Battleship project for my intermediate c++ class

Author: [@isabelleviraldo](https://github.com/isabelleviraldo)

Contact: isabelleviraldo@gmail.com

Date Last Updated: 09/14/2023

## Project Details
Due: 10/18/2023

This assignment is a twist on the popular game Battleship.

The rules are simple. The student must create a program that does the following:

1. Create the battleship playing board ( 10 rows represented by letters and 10 columns represented by numbers)
2. Create the battleship pieces and place them on the board in a random pattern (Ship pieces can only be in an vertical or horizontal pattern, can not be at an angle)
3. The ship pieces cannot overlap
4. Hits are represented with an X and misses are represented with a O
5. Game ends
   - Once all the ship pieces have been found
   - Once the user misses 15 times in a row
   - Uses the sentinel command ( -1 for example)
6. The board must be its own class
7. Each ship is its own instance of the class
8. All classes must be in separate files (header and cpp)

This project is graded on the quality of your code and quality of the game. Add things like titling and narratives to engage your users.

300 points are possible with this project.

200 points are earned for just having a program that works.
The other 100 points are earned based on game's ease of use and visual additions that add to the look and feel of the game.

## battleship-project-step1.txt
Due: 08/29/2023

### Instructions:

Your assignment is to convince me (Your boss) to let you pursue a new game idea. Your new game is called Battleship.

Game Premise:

You are a commander on the cruise missile destroyer USS John Paul Jones, and you need to destroy the enemy fleet. Satellites are down but your sonar works. You know that the enemy is in a 10x10 grid. Your job is to launch your missiles into this 10x10 grid and you can determine if it hits or misses by the sonar register. We know that there is an aircraft carrier, a destroyer, a battleship, a submarine and a frigate and we know how may hits it will take to destroy them. If you miss 15 times, the enemy will coordinate your position and destroy your ship.

Describe the game to me in language that will make me want to let you develop your game. You will be graded on your ability to convince me.

Make sure you tell me how the game works and how you think it will be a success for the company.

Goal of this exercise:

In academics, we like to look at projects and assignments in a very logical and gradable manner. In the workforce, careers are made and broken based off your ability to influence your audience. Your goal is to influence me to fund your project.


## battleship-project-step2.txt
Due: 09/10/2023

### Instructions:

Now it is time for you to start planning. For this step, you have two things you need to complete.

1. With October 20th as your deadline, create a realistic timeline of the steps you are going to have to take to get this task completed. You will use the different elements we will discuss in class on Thursday.
2. I have given you enough in your budget to bring on two other developers. You task is to take a hard look at yourself, including your strengths and weaknesses, and prepare a memo describing the two developers you wish to bring on your team.

## Step 3
Due: 09/24/2023

### Instructions:

With this step we are starting the development phase of project. 

1. Create the board
2. Create the ship class
3. Initialize 5 instances of the ship class:
   - Frigate (size 2)
   - Sub (size 3)
   - Destroyer (size 3)
   - Battleship (size 4)
   - Aircraft Carrier (size 5)
4. The ships take random spots on the board
5. Show each ship position using the first letter of the ship name

