/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 07:55:07 by raweber           #+#    #+#             */
/*   Updated: 2022/09/25 11:42:31 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <algorithm>

//---------------constructors/destructor-------------------------//
Brain::Brain(void) {
	
	std::cout << "Brain default constructor called" << std::endl;
	this->_ideas[0] = "Attend at least one major sporting event: the Super Bowl, the Olympics, the U.S. Open.";
	this->_ideas[1] = "Swim with a dolphin.";
	this->_ideas[2] = "Skydive.";
	this->_ideas[3] = "Have your portrait painted.";
	this->_ideas[4] = "Learn to speak a foreign language and make sure you use it.";
	this->_ideas[5] = "Go skinny-dipping at midnight in the South of France.";
	this->_ideas[6] = "Watch the launch of the space shuttle.";
	this->_ideas[7] = "Spend a whole day eating junk food without feeling guilty.";
	this->_ideas[8] = "Be an extra in a film.";
	this->_ideas[9] = "Tell someone the story of your life, sparing no details.";
	this->_ideas[10] = "Make love on a forest floor.";
	this->_ideas[11] = "Make love on a train.";
	this->_ideas[12] = "Learn to rollerblade.";
	this->_ideas[13] = "Own a room with a view.";
	this->_ideas[14] = "Brew your own beer.";
	this->_ideas[15] = "Learn how to take a compliment.";
	this->_ideas[16] = "Buy a round-the-world air ticket and a rucksack, and run away.";
	this->_ideas[17] = "Grow a beard and leave it for at least a month.";
	this->_ideas[18] = "Give your mother a dozen red roses and tell her you love her.";
	this->_ideas[19] = "Be a member of the audience in a TV show.";
	this->_ideas[20] = "Put your name down to be a passenger on the first tourist shuttle to the moon.";
	this->_ideas[21] = "Send a message in a bottle.";
	this->_ideas[22] = "Ride a camel into the desert.";
	this->_ideas[23] = "Get to know your neighbors.";
	this->_ideas[24] = "Plant a tree.";
	this->_ideas[25] = "Learn not to say yes when you really mean no.";
	this->_ideas[26] = "Write a fan letter to your all-time favorite hero or heroine.";
	this->_ideas[27] = "Visit the Senate and the House of Representatives to see how Congress really works.";
	this->_ideas[28] = "Learn to ballroom dance properly.";
	this->_ideas[29] = "Eat jellied eels from a stall in London.";
	this->_ideas[30] = "Be the boss.";
	this->_ideas[31] = "Fall deeply in love -- helplessly and unconditionally.";
	this->_ideas[32] = "Ride the Trans-Siberian Express across Asia.";
	this->_ideas[33] = "Sit on a jury.";
	this->_ideas[34] = "Write the novel you know you have inside you.";
	this->_ideas[35] = "Go to Walden Pond and read Thoreau while drifting in a canoe.";
	this->_ideas[36] = "Stay out all night dancing and go to work the next day without having gone home (just once).";
	this->_ideas[37] = "Drink beer at Oktoberfest in Munich.";
	this->_ideas[38] = "Be someone's mentor.";
	this->_ideas[39] = "Shower in a waterfall.";
	this->_ideas[40] = "Ask for a raise.";
	this->_ideas[41] = "Learn to play a musical instrument with some degree of skill.";
	this->_ideas[42] = "Teach someone illiterate to read.";
	this->_ideas[43] = "Be one of the first to take a flight on the new Airbus A380.";
	this->_ideas[44] = "Spend a night in a haunted house -- by yourself.";
	this->_ideas[45] = "Write down your personal mission statement, follow it, and revise it from time to time.";
	this->_ideas[46] = "See a lunar eclipse.";
	this->_ideas[47] = "Spend New Year's in an exotic location.";
	this->_ideas[48] = "Get passionate about a cause and spend time helping it, instead of just thinking about it.";
	this->_ideas[49] = "Experience weightlessness.";
	this->_ideas[50] = "Sing a great song in front of an audience.";
	this->_ideas[51] = "Ask someone you've only just met to go on a date.";
	this->_ideas[52] = "Drive across America from coast to coast.";
	this->_ideas[53] = "Make a complete and utter fool of yourself.";
	this->_ideas[54] = "Own one very expensive but absolutely wonderful business suit.";
	this->_ideas[55] = "Write your will.";
	this->_ideas[56] = "Sleep under the stars.";
	this->_ideas[57] = "Take a ride on the highest roller coaster in the country.";
	this->_ideas[58] = "Learn how to complain effectively -- and do it!";
	this->_ideas[59] = "Go wild in Rio during Carnival.";
	this->_ideas[60] = "Spend a whole day reading a great novel.";
	this->_ideas[61] = "Forgive your parents.";
	this->_ideas[62] = "Learn to juggle with three balls.";
	this->_ideas[63] = "Drive the Autobahn.";
	this->_ideas[64] = "Find a job you love.";
	this->_ideas[65] = "Spend Christmas on the beach drinking pina coladas.";
	this->_ideas[66] = "Overcome your fear of failure.";
	this->_ideas[67] = "Raft through the Grand Canyon.";
	this->_ideas[68] = "Donate money and put your name on something: a college scholarship, a bench in the park.";
	this->_ideas[69] = "Buy your own house and then spend time making it into exactly what you want.";
	this->_ideas[70] = "Grow a garden.";
	this->_ideas[71] = "Spend three months getting your body into optimum shape.";
	this->_ideas[72] = "Drive a convertible with the top down and music blaring.";
	this->_ideas[73] = "Accept yourself for who you are.";
	this->_ideas[74] = "Learn to use a microphone and give a speech in public.";
	this->_ideas[75] = "Scuba dive off Australia's Great Barrier Reef.";
	this->_ideas[76] = "Go up in a hot-air balloon.";
	this->_ideas[77] = "Attend one really huge rock concert.";
	this->_ideas[78] = "Kiss someone you've just met on a blind date.";
	this->_ideas[79] = "Be able to handle: your tax forms, Jehovah's Witnesses, your banker, telephone solicitors.";
	this->_ideas[80] = "Give to a charity -- anonymously.";
	this->_ideas[81] = "Lose more money than you can afford at roulette in Vegas.";
	this->_ideas[82] = "Let someone feed you peeled, seedless grapes.";
	this->_ideas[83] = "Kiss the Blarney stone and develop the gift of gab.";
	this->_ideas[84] = "Fart in a crowded space.";
	this->_ideas[85] = "Make love on the kitchen floor.";
	this->_ideas[86] = "Go deep sea fishing and eat your catch.";
	this->_ideas[87] = "Create your own web site.";
	this->_ideas[88] = "Visit the Holy Land.";
	this->_ideas[89] = "Make yourself spend a half-day at a concentration camp and swear never to forget.";
	this->_ideas[90] = "Run to the top of the Statue of Liberty.";
	this->_ideas[91] = "Create your Family Tree.";
	this->_ideas[92] = "Catch a ball in the stands of a major league baseball stadium.";
	this->_ideas[93] = "Make a hole-in-one.";
	this->_ideas[94] = "Ski a double-black diamond run.";
	this->_ideas[95] = "Learn to bartend.";
	this->_ideas[96] = "Run a marathon.";
	this->_ideas[97] = "Look into your child's eyes, see yourself, and smile.";
	this->_ideas[98] = "Reflect on your greatest weakness, and realize how it is your greatest strength.";
	this->_ideas[99] = "Throw a huge party and invite every one of your friends.";
}

Brain::Brain(Brain const &src) {
	
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void) {
	
	std::cout << "Brain destructor called" << std::endl;
}

Brain & Brain::operator=(Brain const &rhs) {

	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

//-------------------functionals-------------------------//

std::string	Brain::getIdea(int i) const {

	return(this->_ideas[i]);
}

void Brain::setIdea(int i, std::string new_idea) {

	this->_ideas[i] = new_idea;
}
