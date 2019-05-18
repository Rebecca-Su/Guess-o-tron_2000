//============================================================================
// Name        : Guess-O-Tron2000.cpp
// Author      : Rebecca Su
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int main();
void catch_e(std::string user_response);

int main() {

	std::string user_response;
	bool continue_game{true};

	std::cout << "Welcome to the Guess-o-tron 2000!" << std::endl;
	std::cout << "Think of a secret number between 1 and 255." << std::endl;
	std::cout << "Are you ready to begin?([Y]es/[N]o)" << std::endl;
	std::cin >> user_response;
	std::cout << "The amazing Guess-o-tron 2000 does not care for foolish human's readiness. We shall start the game!" << std::endl;

	while(continue_game == true)
	{
		int guess_number{(1 + 255) / 2};
		bool not_guessed_yet{true};
		int quantity_guesses{1};
		int upper_bound{255};
		int lower_bound{1};

		while(quantity_guesses <= 8 && not_guessed_yet == true)
		{
			std::cout << "Is your number " << guess_number << "?([H]igher/[L]ower/[Y]es)" << std::endl;
			std::cin >> user_response;
			try
			{
				catch_e(user_response);
			}catch(...)
			{
				std::cout << "You foolish human! Can't you read instructions? The incredible Guess-o-tron 2000 doesn't play with dumb creatures (`^`)" << std::endl;
				continue_game = false;
				break;
			}

			if(user_response == "Y")
			{
				not_guessed_yet = false;
				std::cout << "Hooray, I correctly guessed your secret number (" << guess_number << ") in " << quantity_guesses << " guesses! Bow down to the omnipotent Guess-o-tron 2000\('o')/!" <<std::endl;
				quantity_guesses = 10;
			}
			else
			{
				if(user_response == "H")
					lower_bound  = guess_number + 1;
				if(user_response == "L")
					upper_bound = guess_number - 1;
			}
			guess_number = (upper_bound + lower_bound) / 2;
			quantity_guesses ++;
		}

		if(not_guessed_yet == true && continue_game == true)
		{
			std::cout << "Oh no! You have beaten the magnificent Guess-o-tron 2000! There is no reward for bullying computers (O_O)" << std::endl;
		}
		std::cout << "Do you wish to continue the game?[Y]es/[N]o" << std::endl;
		std::cin >> user_response;

		if(user_response == "N")
		{
			continue_game = false;
			std::cout << "You don't wish to continue? I guess this is goodbye..." << std::endl;
			std::cout << "How could you leave the magnificent Guess-o-tron 2000 behind!? You heartless human (T-T)" << std::endl;
		}
	}


	return 0;
}

void catch_e(std::string user_response)
{
	if(user_response != "Y" && user_response != "H" && user_response != "L")
		throw -1;
}
