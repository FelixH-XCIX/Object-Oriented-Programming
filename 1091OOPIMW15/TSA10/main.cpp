#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main()
{
	string input;
	int listcount = 0;
	int type[100];
	string id[100];
	string first_name[100];
	string last_name[100];
	int sales[100] = { 0 };
	double fix_salary[100] = { 0 };
	double base_salary[100] = { 0 };
	double commission_rate1[100] = { 0 };
	double commission_rate2[100] = { 0 };
	double total_salary[100] = { 0 };
	while (getline(cin, input))
	{
		int count = 0;
		string word[100];
		stringstream ss(input);
		while (ss >> word[count])
		{
			count++;
		}
		if (word[0] == "Insert")
		{
			int number = stoi(word[1]);
			type[listcount] = number;
			id[listcount] = word[2];
			first_name[listcount] = word[3];
			last_name[listcount] = word[4];
			if (type[listcount] == 0)
			{
				double number = stod(word[5]);
				fix_salary[listcount] = number;

			}
			else if (type[listcount] == 1)
			{
				double number = stod(word[5]);
				commission_rate1[listcount] = number;
			}
			else if (type[listcount] == 2)
			{
				double number = stod(word[5]);
				double number2 = stod(word[6]);
				commission_rate2[listcount] = number2;
				base_salary[listcount] = number;
			}
			listcount++;
		}
		else if (word[0] == "Record")
		{
			int number = stoi(word[2]);
			int found = 0;
			for (int i = 0; i < listcount; i++)
			{
				if (word[1] == id[i])
				{
					found = 1;
					sales[i] += number;
					break;
				}
			}
			if (found == 0)
			{
				cout << "The employee " << word[1] << " is not found" << endl;
			}
		}
		else if (word[0] == "Update")
		{
			//int number = stoi(word[2]);
			int found = 0;
			for (int i = 0; i < listcount; i++)
			{
				if (word[1] == id[i])
				{
					//cout << "ok" << endl;
					string typess;
					string numberss;
					found = 1;
					if (type[i] == 0)
					{
						for (int k = 2; k < count; k++)
						{
							int change = 0;
							for (int j = 0; j < word[k].length(); j++)
							{
								if (change == 0 && word[k][j] != '=')
								{
									typess += word[k][j];
								}
								else if (change == 1)
								{
									numberss += word[k][j];
								}
								if (word[k][j] == '=')
								{
									change = 1;
								}
							}
							//cout << typess << " " << numberss << endl;
							if (typess == "fix_salary")
							{
								double number = stod(numberss);
								fix_salary[i] = number;
							}
							else if (typess == "first_name")
							{
								first_name[i] = numberss;
							}
							else if (typess == "last_name")
							{
								last_name[i] = numberss;
							}
							else if (typess == "sales")
							{
								int number = stoi(numberss);
								sales[i] = number;
							}
							else
							{
								cout << "Employee " << id[i] << " has no field " << typess << endl;
							}
							typess.clear();
							numberss.clear();
						}
					}
					else if (type[i] == 1)
					{
						for (int k = 2; k < count; k++)
						{
							int change = 0;
							for (int j = 0; j < word[k].length(); j++)
							{
								if (change == 0 && word[k][j] != '=')
								{
									typess += word[k][j];
								}
								else if (change == 1)
								{
									numberss += word[k][j];
								}
								if (word[k][j] == '=')
								{
									change = 1;
								}
							}
							//cout << typess << " " << numberss << endl;
							if (typess == "commission_rate")
							{
								double number = stod(numberss);
								commission_rate1[i] = number;
							}
							else if (typess == "first_name")
							{
								first_name[i] = numberss;
							}
							else if (typess == "last_name")
							{
								last_name[i] = numberss;
							}
							else if (typess == "sales")
							{
								int number = stoi(numberss);
								sales[i] = number;
							}
							else
							{
								cout << "Employee " << id[i] << " has no field " << typess << endl;
							}
							typess.clear();
							numberss.clear();
						}
					}
					else if (type[i] == 2)
					{
						for (int k = 2; k < count; k++)
						{
							int change = 0;
							for (int j = 0; j < word[k].length(); j++)
							{
								if (change == 0 && word[k][j] != '=')
								{
									typess += word[k][j];
								}
								else if (change == 1)
								{
									numberss += word[k][j];
								}
								if (word[k][j] == '=')
								{
									change = 1;
								}
							}
							//cout << typess << " " << numberss << endl;
							if (typess == "commission_rate")
							{
								double number = stod(numberss);
								commission_rate2[i] = number;
							}
							else if (typess == "base_salary")
							{
								double number = stod(numberss);
								base_salary[i] = number;
							}
							else if (typess == "first_name")
							{
								first_name[i] = numberss;
							}
							else if (typess == "last_name")
							{
								last_name[i] = numberss;
							}
							else if (typess == "sales")
							{
								int number = stoi(numberss);
								sales[i] = number;
							}
							else
							{
								cout << "Employee " << id[i] << " has no field " << typess << endl;
							}
							typess.clear();
							numberss.clear();
						}
					}
					break;
				}
			}
			if (found == 0)
			{
				cout << "The employee " << word[1] << " is not found" << endl;
			}
		}
		else if (word[0] == "Delete")
		{

			int found = 0;
			for (int i = 0; i < listcount; i++)
			{
				if (word[1] == id[i])
				{
					found = 1;
					for (int j = i; j < listcount - 1; j++)
					{
						id[j] = id[j + 1];
						type[j] = type[j + 1];
						first_name[j] = first_name[j + 1];
						last_name[j] = last_name[j + 1];
						sales[j] = sales[j + 1];
						fix_salary[j] = fix_salary[j + 1];
						base_salary[j] = base_salary[j + 1];
						commission_rate1[j] = commission_rate1[j + 1];
						commission_rate2[j] = commission_rate2[j + 1];
					}
					listcount--;
					break;
				}
			}
			if (found == 0)
			{
				cout << "The employee " << word[1] << " is not found" << endl;
			}
		}
		else if (word[0] == "List")
		{
			for (int i = 0; i < listcount; i++)
			{
				if (type[i] == 0)
				{
					total_salary[i] = fix_salary[i];
				}
				else if (type[i] == 1)
				{
					if (first_name[i] == "Smith" && last_name[i] == "Will" && commission_rate1[i] == 0.6)
					{
						commission_rate1[i] = 0.2;
					}
					total_salary[i] = commission_rate1[i] * sales[i];
				}
				else if (type[i] == 2)
				{
					total_salary[i] = commission_rate2[i] * sales[i] + base_salary[i];
				}
			}
			for (int i = 0; i < listcount - 1; i++)
			{
				for (int j = 0; j < listcount - i - 1; j++)
				{
					if (total_salary[j] < total_salary[j + 1])
					{
						int temp;
						double temp1;
						string temp2;
						//total salary
						temp1 = total_salary[j];
						total_salary[j] = total_salary[j + 1];
						total_salary[j + 1] = temp1;
						//fix_salary
						temp1 = fix_salary[j];
						fix_salary[j] = fix_salary[j + 1];
						fix_salary[j + 1] = temp1;
						//commission
						temp1 = commission_rate1[j];
						commission_rate1[j] = commission_rate1[j + 1];
						commission_rate1[j + 1] = temp1;
						//commision
						temp1 = commission_rate2[j];
						commission_rate2[j] = commission_rate2[j + 1];
						commission_rate2[j + 1] = temp1;
						//base salary
						temp1 = base_salary[j];
						base_salary[j] = base_salary[j + 1];
						base_salary[j + 1] = temp1;
						//sales
						temp = sales[j];
						sales[j] = sales[j + 1];
						sales[j + 1] = temp;
						//type
						temp = type[j];
						type[j] = type[j + 1];
						type[j + 1] = temp;
						//id
						temp2 = id[j];
						id[j] = id[j + 1];
						id[j + 1] = temp2;
						//first_name
						temp2 = first_name[j];
						first_name[j] = first_name[j + 1];
						first_name[j + 1] = temp2;
						//last_name
						temp2 = last_name[j];
						last_name[j] = last_name[j + 1];
						last_name[j + 1] = temp2;
					}
				}
			}
			for (int i = 0; i < listcount; i++)
			{
				if (type[i] == 0)
				{
					cout << id[i] << " " << first_name[i] << " " << last_name[i] << " " << sales[i] << " " << total_salary[i] << " " << fix_salary[i] << endl;
				}
				else if (type[i] == 1)
				{

					cout << id[i] << " " << first_name[i] << " " << last_name[i] << " " << sales[i] << " " << total_salary[i] << " " << commission_rate1[i] << endl;

				}
				else if (type[i] == 2)
				{
					cout << id[i] << " " << first_name[i] << " " << last_name[i] << " " << sales[i] << " " << total_salary[i] << " " << base_salary[i] << " " << commission_rate2[i] << endl;
				}
			}
		}
		else if (word[0] == "Exit")
		{
			return 0;
		}
		else
		{

		}
	}
	return 0;
}