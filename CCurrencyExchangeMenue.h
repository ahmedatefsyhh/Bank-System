#pragma once
#include <iostream>
#include "CScreen.h"
#include "CInputValidate.h"
#include "CCurrenciesListScreen.h"
#include "CFindCurrencyScreen.h"
#include "CUpdateCurrencyRateScreen.h"
#include "CCurrencyCalculatorScreen.h"
#include <iomanip>

using namespace std;

class CCurrencyExchangeMenue :protected CScreen
{

private:
	enum enCurrenciesMainMenueOptions {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
		eCurrencyCalculator = 4, eMainMenue = 5
	};

	static short ReadCurrenciesMainMenueOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = CInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _GoBackToCurrenciesMenue()
	{
		cout << "\n\nPress any key to go back to Currencies Menue...";
		system("pause>0");
		ShowCurrenciesMenue();
	}

	static void _ShowCurrenciesListScreen()
	{
		//cout << "\nCurriencies List Screen Will Be Here.\n";
		CCurrenciesListScreen::ShowCurrenciesListScreen();

	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen Will Be Here.\n";
		CFindCurrencyScreen::ShowFindCurrencyScreen();

	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		//cout << "\nUpdate Currency Rate Screen Will Be Here.\n";
		CUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency Calculator Screen Will Be Here.\n";
		CCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrenciesMainMenueOptions)
	{

		switch (CurrenciesMainMenueOptions)
		{
		case enCurrenciesMainMenueOptions::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrenciesMenue();
			break;
		}

		case enCurrenciesMainMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break;
		}

		case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
		{
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrenciesMenue();
			break;
		}

		case enCurrenciesMainMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenue();
			break;
		}

		case enCurrenciesMainMenueOptions::eMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;
		}
		}

	}

public:

	static void ShowCurrenciesMenue()
	{
		if (!CScreen::CheckAccessRights(CUser::enPermissions::pCurrencyExchange))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("    Currancy Exhange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrenciesMainMenueOptions((enCurrenciesMainMenueOptions)ReadCurrenciesMainMenueOptions());
	}

};

