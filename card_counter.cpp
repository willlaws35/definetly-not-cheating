using namespace std;
#include <iostream>

void more_info_num_players() {
	cout << "number of players refers to the total players including the dealer.\n";
	cout << "for program purposes games are considered to have a max of 7 people.\n";
	cout << "please enter number of players 2-7.\n";

}

void more_info_player_pos() {
	cout << "player position, refers to your placement amongst the players from\n";
	cout << "your perspective, for example in a four person game (noting the dealer as position 1)\n";
	cout << "considering your placement as position '3' would mean you the second person dealt to\n";
	cout << "enter player position 2-7\n";
}

void more_info_deal_pattern() {
	cout << "deal pattern is how cards are handed to players, there are two noteworthy distributuions\n";
	cout << "pattern '1122' or pattern '1212' the first 1122 is where each player is handed one card\n";
	cout << "then after each player has one card, a second is handed to each player. The second method\n";
	cout << "1212 is where each player is given both cards before moving onto the next player.\n";
	cout << "enter deal pattern, either 1122, or 1212.\n";
}

int player_total_validate(string players) {
	int ret_val = -1;
	char abstract_char = players[0];
	switch (abstract_char) {
	case'2':
		ret_val = 2;
	case'3':
		ret_val = 3;
	case'4':
		ret_val = 4;
	case'5':
		ret_val = 5;
	case'6':
		ret_val = 6;
	case'7':
		ret_val = 7;
	}
	return ret_val;
}


int get_num_players() {
	int ret_val = -1;
	string players;
	while (ret_val == -1) {
		cout << "enter number of players 2-7 \n";
		cin >> players;
		if (players == "more") {
			more_info_num_players();
			cin >> players;
			cout << "\n";
		}
		ret_val = player_total_validate(players);
	}
	return ret_val;
}

int get_player_pos() {
	int ret_val = -1;
	string player_pos;
	while (ret_val == -1) {
		cout << "enter player position 2-7\n";
		cin >> player_pos;
		if (player_pos == "more") {
			more_info_player_pos();
			cin >> player_pos;
			cout << "\n";
		}
		ret_val = player_total_validate(player_pos);
	}
	return ret_val;
}

int get_deal_pattern() {
	int ret_val = -1;
	string deal_pattern;
	char abstract_deal_type;
	while (ret_val == -1) {
		cout << "enter dealer pattern (1 for 1122 or 2 for 1212)\n";
		cin >> deal_pattern;
		if (deal_pattern == "more") {
			more_info_deal_pattern();
			cin >> deal_pattern;
			cout << "\n";
		}
		switch (deal_pattern[1]) {
		case'1':
			ret_val = 1122;
		case'2':
			ret_val = 1212;
		}
	}
	return ret_val;
}

bool info_checker(int card_index[52]) {
	int full_check = 0;
	bool ret_val = false;
	for (int i = 0; i < 52; i++) {
		if (card_index[i] != -858993460) {
			full_check++;
		}
	}
	if (full_check == 52) {
		ret_val = true;
	}
	return ret_val;
}

int occupation_checker(int card_index[52]) {
	int full_check = 0;
	int ret_val = 0;
	for (int i = 0; i < 52; i++) {
		if (card_index[i] != -858993460) {
			full_check++;
		}
	}
	return ret_val;
}


int main()
{
	char choice;
	char choice_1 = ' ';
	int previous_total = 0;
	int choice_run_num = 0;
	int run = 1;
	int n1;
	int n2;
	int n;
	int needed = 0;
	int temp_indexer;
	int established_pointer = 0;
	int card_index[52];
	int players;
	int player_pos;
	int deal_pattern;
	int establish_pointer = 0;
	int wreckless;
	int deciding_factor = 50;
	char temp_shuffle = ' ';
	bool shuffle = false;
	bool incomplete_running = false;

	cout << "*The potentially amazing card counter for 21*\n";

	cout << "*****************value setup*****************\n";
	cout << "type 'more' for further info on a setup term.\n";
	cout << "*********************************************\n";

	players = get_num_players();
	player_pos = get_player_pos();
	deal_pattern = get_deal_pattern();


	//temp advisor and data gatherer
	if (info_checker(card_index) == false) {
		cout << "**************************************************\n";
		cout << "***inconclusive data set, using predictive only***\n";
		cout << "****data will be gathered through these games.****\n";
		cout << "**************************************************\n";

		cout << "please decide playable risk factor:\n";
		cout << "1 = very safe\n";
		cout << "2 = safe\n";
		cout << "3 = risky\n";
		cin >> wreckless;
		switch (wreckless) {
		case(1):
			wreckless = 60;
			break;
		case(2):
			wreckless = 50;
			break;
		case(3):
			wreckless = 40;
			break;
		default:
			cout << "invalid option, proceeding in safe mode.\n";
			wreckless = 50;
			break;
		}

		while (run > 0) {
			if (choice_1 == '2') {
				n1 = previous_total;
				cout << "continuing total = " << n1 << "\n";
			}
			else {
				cout << "enter card value 1\n";
				cin >> n1;
				cout << "\n";
			}
			cout << "enter card value 2\n";
			cin >> n2;
			cout << "\n";
			n = n1 + n2;
			cout << "your card total is ," << n << "\n";
			if (n <= 10) {
				cout << "pick up success rate = 100%\n";
				cout << "***recommend pick up***\n";
			}
			else {
				needed = 21 - n;
				cout << "total required for 21 = " << needed << "\n";
				if (needed == 0) {
					cout << "stick success rate = 100%\n";
					cout << "***recommend stick***\n";
				}
				if (needed >= 10) {
					int ratio = 3;
					float y = 13 - (needed - 1);
					ratio = ratio + y;
					float test_1 = 7.692307692 * ratio;
					cout << "probability of success = " << test_1 << "%\n";
					float fail_1 = 100 - test_1;
					cout << "probability of failure = " << fail_1 << "%\n";
					if (test_1 >= 50) {
						cout << "***recommend pick up***\n";
					}
					else {
						cout << "***recommend stick***\n";
					}
				}
				else if (0 < needed < 10) {
					float test_val = 7.6923076092 * needed;
					cout << "probability of success = " << test_val << "\n";
					float fail_val = 100 - test_val;
					cout << "probability of failure = " << fail_val << "\n";
					if (test_val >= 50) {
						cout << "***recommend pick up***\n";
					}
					else {
						cout << "***recommend stick***\n";
					}
				}
				cout << "do you wish to go again ? (y/n)\n";
				cin >> choice;
				if (choice == 'n') {
					cout << "you have chosen to exit, happy playing.\n";
					run = run - 1;
					exit(0);
				}
				else if (choice == 'y') {
					cout << "new round or continuing game? 1 for new, 2 for continue\n";
					cin >> choice_1;
					if (choice_1 == '1') {
						cout << "starting new round...\n";
					}
					else if (choice_1 == '2') {
						cout << "continuing previous round.\n";
						previous_total = n1 + n2;
						choice_run_num++;
					}
					else if (choice_1 == 'D') {
						int nothing_0;
						for (int j = 0; j < 52; j++) {
							cout << card_index[j] << "\n";
						}
						cout << "option will now quit enter any key\n";
						cin >> nothing_0;
						exit(0);
					}
					cout << "has dealer shuffled ? (y/n)\n";
					cin >> temp_shuffle;
					switch (temp_shuffle) {
					case 'y':
						cout << "dealer has shuffled resetting data compiled\n";
						for (int k = 0; k < 52; k++) {
							card_index[k] = -858993460;
						}
						cout << "***data_reset***\n";
						break;
					case 'n':
						cout << "dealer has not shuffled\n";
						cout << "recording game data***\n";
						cout << "\n";
						if (deal_pattern == 1122) {
							if (establish_pointer == 0) {
								temp_indexer = player_pos;
								if ((temp_indexer - players) < 0) {
									card_index[(temp_indexer - players) + 52];
								}
								else if ((temp_indexer - players)>52){
									card_index[(temp_indexer - players) - 52];
								}
								else {
									card_index[temp_indexer - players] = n1;
								}
								card_index[temp_indexer] = n2;					
								established_pointer = temp_indexer + (players * 2);	
							}
						}
						else if (deal_pattern == 1212) {
							if (establish_pointer == 0) {
								temp_indexer = player_pos * 2;
								card_index[temp_indexer - 1] = n1;
								card_index[temp_indexer] = n2;
								establish_pointer++;
								if (players > 5) {
									established_pointer = temp_indexer + ((players * 2) + 3);
								}
								else {
									established_pointer = temp_indexer + (players * 2);
								}
							}
							else {
								card_index[established_pointer - 1] = n1;
								card_index[established_pointer] = n2;
								if (choice_1 == '2') {
									if (choice_run_num > 1) {
										card_index[established_pointer] = n2;
										established_pointer++;
									}
									else {
										card_index[established_pointer - 1] = n1;
										card_index[established_pointer] = n2;
										established_pointer++;
									}
								}
								else {
									card_index[established_pointer - 1] = n1;
									card_index[established_pointer] = n2;
									if (players > 5) {
										established_pointer = temp_indexer + ((players * 2) + 3);
									}
									else {
										established_pointer = temp_indexer + (players * 2);
									}
									if (established_pointer > 52) {
										established_pointer = established_pointer - 52;
									}
								}
							}
						}
					}
				}	
				//check data occupation, see if enough data to predict draws.
				int nothing;
				if (occupation_checker(card_index) >= 39) {
					float occupational_average = occupation_checker(card_index) * 1.9;
					cout << "********************************************************************************************\n";
					cout << "*A minimum of " << occupational_average << " of cards have been recorded, would you like to use compiled data ? (y/n).*\n";
					cout << "********************************************************************************************\n";
					char temp_in;
					cin >> temp_in;
					switch (temp_in) {
					case'y':
						cout << "you have chosen to run with in complete data, some results may be missing,\n";
						cout << " as a result advice may not always be given\n";
						run = 1;
						incomplete_running = true;
					default:
						cout << "maintaining analytical predicitions.\n";
					}

					cout << "not yet written....";
					cin >> nothing;
					exit(0);
				}
				else if (occupation_checker(card_index) == 52) {
					cout << "*************************************************************\n";
					cout << "deck data compiled - transitioning to historical predictions.\n";
					cout << "*************************************************************\n";
					run = 1;
					incomplete_running = true;
					cout << "not yet written....";
					cin >> nothing;
					exit(0);
				}
			}
		}
	}
}