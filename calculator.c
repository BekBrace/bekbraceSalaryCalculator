#include <stdio.h>

// Define ANSI color codes for text color
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"

float calculateZUSContributions(float grossSalary) {
    // Define ZUS contribution rates
    float oldAgePensionRate = 0.0976;
    float pensionRate = 0.015;
    float sicknessInsuranceRate = 0.0245;
    float healthInsuranceRate = 0.09;
    float accidentInsuranceRate = 0.0167;

    // Calculate ZUS contributions for employee
    float oldAgePension = grossSalary * oldAgePensionRate;
    float pension = grossSalary * pensionRate;
    float sicknessInsurance = grossSalary * sicknessInsuranceRate;
    float healthInsuranceBasis = grossSalary - pension - oldAgePension;
    float healthInsurance = healthInsuranceBasis * healthInsuranceRate;
    float accidentInsurance = healthInsuranceBasis * accidentInsuranceRate;
    float totalZUSContributionsEmployee = oldAgePension + pension + sicknessInsurance + healthInsurance + accidentInsurance;

    // Calculate ZUS contributions for employer
    float totalZUSContributionsEmployer = oldAgePension + pension + accidentInsurance;

    printf(ANSI_COLOR_GREEN "\nEMPLOYEE CONTRIBUTIONS\n" ANSI_COLOR_RESET);
    printf("Old-age pension insurance: %.2f PLN (ZUS) - provides retirement benefits.\n", oldAgePension);
    printf("Pension insurance: %.2f PLN (ZUS) - contributes to pension fund.\n", pension);
    printf("Sickness insurance: %.2f PLN (ZUS) - covers costs during illness.\n", sicknessInsurance);
    printf("Health insurance: %.2f PLN (ZUS) - covers medical expenses.\n", healthInsurance);
    printf("Work accident insurance: %.2f PLN (ZUS) - covers accidents at work.\n", accidentInsurance);
    printf("Total ZUS contribution (employee): %.2f PLN\n", totalZUSContributionsEmployee);

    printf(ANSI_COLOR_CYAN "\n==================================================================\n" ANSI_COLOR_RESET);

    printf(ANSI_COLOR_YELLOW "\nZUS CONTRIBUTIONS EMPLOYER\n" ANSI_COLOR_RESET);
    printf("Old-age pension insurance: %.2f PLN (ZUS) - provides retirement benefits.\n", oldAgePension);
    printf("Pension insurance: %.2f PLN (ZUS) - contributes to pension fund.\n", pension);
    printf("Work accident insurance: %.2f PLN (ZUS) - covers accidents at work.\n", accidentInsurance);
    printf("Total ZUS contributions (employer): %.2f PLN\n", totalZUSContributionsEmployer);

    return totalZUSContributionsEmployee;
}

float calculateTax(float grossSalary) {
    float incomeCosts = 250;
    float taxRelief = 300;
    float taxationThreshold = 120000;
    float taxRate = (grossSalary > taxationThreshold) ? 0.32 : 0.12;
    float basisForTaxation = grossSalary - incomeCosts - taxRelief;
    float tax = basisForTaxation * taxRate;
    float netToBePaid = tax;

    printf(ANSI_COLOR_MAGENTA "\n==================================================================\n" ANSI_COLOR_RESET);

    printf(ANSI_COLOR_BLUE "\nTAXATION\n" ANSI_COLOR_RESET);
    printf("Basis for taxation: %.2f PLN - total income after deductions.\n", basisForTaxation);
    printf("Tax relief: %.2f PLN - deduction for specific expenses.\n", taxRelief);
    printf("Taxation rate: %.0f%% - percentage of income subject to tax.\n", taxRate * 100);
    printf("Tax advance: %.2f PLN - estimated tax to be paid.\n", tax);
    printf("NET to be paid to employee: %.2f PLN\n", netToBePaid);

    return netToBePaid;
}

int main() {
    float grossSalary;
    printf("Enter the gross salary (PLN): ");
    scanf("%f", &grossSalary);

    printf(ANSI_COLOR_CYAN "\n==================================================================\n" ANSI_COLOR_RESET);
    float totalZUSContributions = calculateZUSContributions(grossSalary);
    float tax = calculateTax(grossSalary);

    float netSalary = grossSalary - totalZUSContributions - tax;
    printf(ANSI_COLOR_YELLOW "\nNET SALARY TO BE PAID TO EMPLOYEE: %.2f PLN\n" ANSI_COLOR_RESET, netSalary);

    return 0;
}
