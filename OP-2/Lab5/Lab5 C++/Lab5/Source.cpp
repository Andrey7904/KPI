#include "Header.h"

int main() {
	char a;
	int n=0;
	Detail* root = NULL;
	Detail* current = new Detail;
	current = root;
	cout << "Do you want to add new detail?(Y/N): ";
	cin >> a;
	 while (a != 'n' && a != 'N') {
		 Detail* newOne = new Detail;
		 cin.ignore();
		 cout << endl << "Enter detail name: ";
		 getline(cin, newOne->detail);
		 cout << endl << "Enter amount: ";
		 cin >> newOne->amount;
		 cin.ignore();
		 cout << endl << "Enter Provider: ";
		 getline(cin, newOne->provider);
		 if (n == 0) {
			 root = newOne;
			 current = newOne;
		 }
		 else {
			 add_detail(newOne, root);
		 }
		 n++;

		 cout <<endl<< "Do you want to add new detail?(Y/N): ";
		 cin >> a;
	}

	 print_tree(root);

	 vector<int>detailamount(n);
	 int i=0;
	 vector<string>providers(n);

	 biggest_provider(root,detailamount,i,providers);

	 auto iter = detailamount.cbegin(); 
	 auto iter2 = providers.cbegin();

	 for (int i = 0; i < detailamount.size(); i++) {
		 for (int j = i+1; j < detailamount.size(); j++) {
			 if (providers[i] == providers[j]) {
				 detailamount[i] += detailamount[j];
				 detailamount.erase(iter + j);
				 providers.erase(iter2 + j);
			 }
		 }
	 }
	 int temp;
	 int temp_index;
	 int max,max_index;
	 max = *max_element(detailamount.begin(), detailamount.end());
	 for (int i = 0; i < detailamount.size(); i++) {
		 if (detailamount[i] == max) {
			 max_index = i;
		 }
	 }
	cout <<endl<< "Biggest provider is: "<<providers[max_index]<<" with details amount: "<<max;
}