#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream> 
using namespace std;

float calculateFare(int pickup, int dropoff) {
    const float pricePerStation = 2.50;
    int stations = abs(pickup - dropoff);
    return stations * pricePerStation;
}

int main() {
    int bookingCount = 0;
    string username;

    struct Booking {
        string pickup;
        string dropoff;
        string time;
        float fare;
    };

    Booking bookings[1000];
    bool loggedIn = false;

    while (true) {
        if (!loggedIn) {
login:
            system("cls");
            cout << "MyWay Bus Booking System\n";
            cout << "1. Login\n2. Exit\n";
            cout << "\nSelect option: ";
            int choice;
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\nInvalid input. Please enter a number.\n\n";
                system("pause");
                goto login;
            }
            if (choice == 1) {
                system("cls");
                cout << "Enter your username: ";
                cin >> username;
                loggedIn = true;
                cout << "\nLogin successful. Welcome, " << username << "!\n\n";
                system("pause");
            } else if (choice == 2) {
                break;
            } else {
                cout << "Unknown selection.\n";
                system("pause");
            }
        } else {
            system("cls");
            cout << "MyWay Bus Booking System - Hello, " << username << "!\n";
            cout << "1. Make Your Booking\n2. Update Booking\n3. View Booking\n4. Delete Booking\n5. Logout\n6. Exit\n";
            cout << "\nSelect option: ";
            int choice2;
            if (!(cin >> choice2)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number.\n";
                system("pause");
                continue;
            }

            int pickup, dropoff, timechoice;
            string locations[] = { "", "DPulzeMallX", "Apple Store", "Mamak Power", "IoI Mall" };
            string times[] = { "", "4.00 p.m.", "5.00 p.m.", "6.00 p.m." };

            if (choice2 == 1) {
booking:
                system("cls");
                cout << "Booking\n";
                cout << "Please Choose Your Pickup Location: \n";
                cout << "1. DPulzeMallX \n2. Apple Store \n3. Mamak Power\n4. IoI Mall\n";
                cout << "\nSelect option: ";
                if (!(cin >> pickup) || pickup < 1 || pickup > 4) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid selection.\n";
                    system("pause");
                    goto booking;
                }
                cout << "\n\nPlease Choose Your DropOff Location: \n";
                cout << "1. DPulzeMallX \n2. Apple Store \n3. Mamak Power\n4. IoI Mall\n";
                cout << "\nSelect option: ";
                if (!(cin >> dropoff) || dropoff < 1 || dropoff > 4) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid selection.\n";
                    system("pause");
                    goto booking;
                }
                if (pickup == dropoff) {
                    cout << "\nPickup and DropOff cannot be the same location. Please Try Again\n";
                    system("pause");
                    goto booking;
                }
                cout << "\n\nPlease Choose Your Pickup Time: \n";
                cout << "1. 4.00 p.m. \n2. 5.00 p.m.\n3. 6.00 p.m.\n";
                cout << "\nSelect option: ";
                if (!(cin >> timechoice) || timechoice < 1 || timechoice > 3) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid time selection.\n";
                    system("pause");
                    goto booking;
                }
                float fare = calculateFare(pickup, dropoff);
                cout << "\n\nYou Have Made A Booking To PickUp From: " << locations[pickup]
                     << " And DropOff At: " << locations[dropoff]
                     << " At: " << times[timechoice] << "\n";
                cout << "Total Fare: RM " << fixed << setprecision(2) << fare << "\n";
                cout << "Please Confirm Your Booking By Entering (Y/N): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    bookings[bookingCount++] = { locations[pickup], locations[dropoff], times[timechoice], fare };
                    cout << "Booking Confirmed! Thank you for using MyWay Bus Booking System.\n";
                } else {
                    cout << "Booking Cancelled.\n";
                    system("pause");
                    goto booking;
                }
                system("pause");
            } else if (choice2 == 2) {
                system("cls");
                if (bookingCount == 0) {
                    cout << "No bookings to update.\n";
                    system("pause");
                    continue;
                }
                cout << "Update Booking\n";
                for (int i = 0; i < bookingCount; i++) {
                    cout << i + 1 << ". From " << bookings[i].pickup << " To " << bookings[i].dropoff
                         << " At " << bookings[i].time << "\n";
                }
updatebooking:
                cout << "\nEnter booking number you would like to update: ";
                int index;
                if (!(cin >> index) || index < 1 || index > bookingCount) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid booking number.\n";
                    system("pause");
                    goto updatebooking;
                }
                index--;
                cout << "\nEnter your new pickup location:\n";
                cout << "1. DPulzeMallX \n2. Apple Store \n3. Mamak Power\n4. IoI Mall\n";
                cout << "\nSelect option: ";
                cin >> pickup;
                cout << "\n\nEnter your new dropoff location:\n";
                cout << "1. DPulzeMallX \n2. Apple Store \n3. Mamak Power\n4. IoI Mall\n";
                cout << "\nSelect option: ";
                cin >> dropoff;
                if (pickup == dropoff) {
                    cout << "\nPickup and DropOff cannot be the same location. Please Try Again\n";
                    system("pause");
                    goto updatebooking;
                }
                cout << "\n\nEnter your new pickup time:\n";
                cout << "1. 4.00 p.m. \n2. 5.00 p.m. \n3. 6.00 p.m.\n";
                cout << "\nSelect option: ";
                cin >> timechoice;
                if (pickup < 1 || pickup > 4 || dropoff < 1 || dropoff > 4 || timechoice < 1 || timechoice > 3) {
                    cout << "Invalid input for update.\n";
                    system("pause");
                    goto updatebooking;
                }
                float fare = calculateFare(pickup, dropoff);
                cout << "\n\nYou Have Made A Booking To PickUp From: " << locations[pickup]
                     << " And DropOff At: " << locations[dropoff]
                     << " At: " << times[timechoice] << "\n";
                cout << "Total Fare: RM " << fixed << setprecision(2) << fare << "\n";
                cout << "Please Confirm Your New Updated Booking By Entering (Y/N): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    bookings[index] = { locations[pickup], locations[dropoff], times[timechoice], fare };
                    cout << "\n\nBooking updated!\n";
                } else {
                    cout << "Update cancelled.\n";
                }
                system("pause");
            } else if (choice2 == 3) {
                system("cls");
                cout << "Your Bookings\n";
                if (bookingCount == 0) {
                    cout << "No bookings yet.\n";
                } else {
                    for (int i = 0; i < bookingCount; i++) {
                        cout << i + 1 << ". From " << bookings[i].pickup
                             << " To " << bookings[i].dropoff
                             << " At " << bookings[i].time
                             << " Fare: RM " << fixed << setprecision(2) << bookings[i].fare << "\n";
                    }
                    cout << "\n1. Proceed with Payment & Print Receipt\n2. Back to Menu\n";
                    cout << "Select option: ";
                    int payChoice;
                    cin >> payChoice;
                    if (payChoice == 1) {
                        ofstream receipt("receipt.txt");
                        if (!receipt) {
                            cout << "\nError: Could not create receipt file.\n";
                        } else {
                            receipt << "=====================================\n";
                            receipt << "        MyWay Bus Booking Receipt    \n";
                            receipt << "=====================================\n";
                            receipt << "Customer : " << username << "\n";
                            receipt << "-------------------------------------\n";
                            receipt << left << setw(8) << "No."
                                    << setw(15) << "From"
                                    << setw(15) << "To"
                                    << setw(10) << "Time"
                                    << setw(8) << "Fare\n";
                            receipt << "-------------------------------------\n";
                            float total = 0;
                            for (int i = 0; i < bookingCount; i++) {
                                receipt << left << setw(8) << i + 1
                                        << setw(15) << bookings[i].pickup
                                        << setw(15) << bookings[i].dropoff
                                        << setw(10) << bookings[i].time
                                        << "RM " << fixed << setprecision(2) << bookings[i].fare << "\n";
                                total += bookings[i].fare;
                            }
                            receipt << "-------------------------------------\n";
                            receipt << "Total Amount: RM " << fixed << setprecision(2) << total << "\n";
                            receipt << "=====================================\n";
                            receipt << "   Thank you for your payment!       \n";
                            receipt << " Your receipt has been generated.    \n";
                            receipt << "=====================================\n";
                            receipt.close();

                            cout << "\nThank you for your payment!\n";
                            cout << "Your receipt (receipt.txt) has been saved in the SAME folder as this program.\n";
                        }
                    }
                }
                system("pause");
            } else if (choice2 == 4) {
                system("cls");
                if (bookingCount == 0) {
                    cout << "No bookings to delete.\n";
                    system("pause");
                    continue;
                }
                cout << "Delete Booking\n";
                for (int i = 0; i < bookingCount; i++) {
                    cout << i + 1 << ". From " << bookings[i].pickup << " To " << bookings[i].dropoff
                         << " At " << bookings[i].time
                         << " Fare: RM " << fixed << setprecision(2) << bookings[i].fare << "\n";
                }
                cout << "\nEnter the booking's number you would like to delete: ";
                int index;
                if (!(cin >> index) || index < 1 || index > bookingCount) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid booking number.\n";
                    system("pause");
                    continue;
                }
                index--;
                for (int i = index; i < bookingCount - 1; i++) {
                    bookings[i] = bookings[i + 1];
                }
                bookingCount--;
                cout << "Booking deleted!\n";
                system("pause");
            } else if (choice2 == 5) {
                loggedIn = false;
                cout << "Logged out.\n";
                system("pause");
            } else if (choice2 == 6) {
                break;
            } else {
                cout << "Unknown command.\n";
                system("pause");
            }
        }
    }
    return 0;
}

