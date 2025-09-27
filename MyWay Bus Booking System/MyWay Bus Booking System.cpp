#include <iostream>
#include <string>
#include <iomanip>


float calculateFare(int pickup, int dropoff) {
    const float pricePerStation = 2.50;
    int stations = std::abs(pickup - dropoff);
    return stations * pricePerStation;
}


int main() {
    const std::string USER = "customer";
    const std::string PASS = "12345";
    int bookingCount = 0;

    struct Booking {
        std::string pickup;
        std::string dropoff;
        std::string time;
        float fare;
    };

    Booking bookings[1000];

    bool loggedIn = false;

    while (true) {
        if (!loggedIn) {
        login:
            system("cls");
            std::cout << "MyWay Bus Booking System\n";
            std::cout << "1. Login\n2. Exit\n";
            std::cout << "\nSelect option: ";

            int choice;
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "\n\nInvalid input. Please enter a number.\n\n";
                system("pause");
                goto login;
            }

            if (choice == 1) {
                std::string username, password;
                system("cls");
                std::cout << "Username: "; std::cin >> username;
                std::cout << "Password: "; std::cin >> password;

                if (username == USER && password == PASS) {
                    loggedIn = true;
                    std::cout << "\nLogin successful. Welcome, " << USER << "!\n\n";
                }
                else {
                    std::cout << "\nLogin failed. Please Try Again\n\n";
                    system("pause");
                    goto login;
                }
            }
            else if (choice == 2) {
                break;
            }
            else {
                std::cout << "Unknown selection.\n";
            }
        }
        else {
            system("pause");
            system("cls");
            std::cout << "MyWay Bus Booking System\n";
            std::cout << "1. Make Your Boooking \n2. Update Booking\n3. View Booking\n4. Delete Booking\n5. Logout\n6. Exit\n";
            std::cout << "\nSelect option: ";

            int choice2;
            if (!(std::cin >> choice2)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                system("pause");
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            int pickup;
            int dropoff;
            int timechoice;

            std::string locations[] = { "", "DPulzeMallX", "Apple Store", "Mamak Power", "IoI Mall" };
            std::string times[] = { "", "4.00 p.m.", "5.00 p.m.", "6.00 p.m." };


            if (choice2 == 1) {
            booking:
                system("cls");
                std::cout << "Booking\n";
                std::cout << "Please Choose Your Pickup Location: \n";
                std::cout << "1. DPulzeMallX \n2. Apple Store \n3. Mamak Power\n4. IoI Mall\n";
                std::cout << "\nSelect option: ";

                if (!(std::cin >> pickup)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    system("pause");
                    std::cout << "Invalid input. Please enter a number.\n";
                    return 0;
                }

                std::cout << "\n\nPlease Choose Your DropOff Location: \n";
                std::cout << "1. DPulzeMallX \n2. Apple Store \n3. Mamak Power\n4. IoI Mall\n";
                std::cout << "\nSelect option: ";

                if (!(std::cin >> dropoff)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    system("pause");
                    std::cout << "Invalid input. Please enter a number.\n";
                    return 0;
                }

                if (pickup < 1 || pickup > 4 || dropoff < 1 || dropoff > 4) {
                    std::cout << "Invalid selection.\n";
                    goto booking;
                }

                if (pickup == dropoff) {
                    std::cout << "\nPickup and DropOff cannot be the same location. Please Try Again\n";
                    system("pause");
                    goto booking;
                }

                std::cout << "\n\nPlease Choose Your Pickup Time: \n";
                std::cout << "1. 4.00 p.m. \n2. 5.00 p.m.\n3. 6.00 p.m.\n";
                std::cout << "\nSelect option: ";

                if (!(std::cin >> timechoice)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    system("pause");
                    std::cout << "Invalid input. Please enter a number.\n";
                    return 0;
                }

                float fare = calculateFare(pickup, dropoff);

                std::cout << "\n\nYou Have Made A Booking To PickUp From: "
                    << locations[pickup]
                    << " And DropOff At: "
                    << locations[dropoff]
                    << " At: "
                    << times[timechoice]
                    << "\n";

                std::cout << "Total Fare: RM " << std::fixed << std::setprecision(2) << fare << "\n";

                std::cout << "Please Confirm Your Booking By Entering (y/Y): ";

                char confirm;
                std::cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    bookings[bookingCount++] = { locations[pickup], locations[dropoff], times[timechoice], fare };

                    std::cout << "Booking Confirmed! Thank you for using MyWay Bus Booking System.\n";
                }

                else {
                    std::cout << "Booking Cancelled.\n";
                    goto booking;
                }
            }

            else if (choice2 == 2) {
                system("cls");
                if (bookingCount == 0) {
                    std::cout << "No bookings to update.\n";
                    system("pause");
                    continue;
                }
                std::cout << "Update Booking\n";
                for (int i = 0; i < bookingCount; i++) {
                    std::cout << i + 1 << ". From " << bookings[i].pickup
                        << " To " << bookings[i].dropoff
                        << " At " << bookings[i].time << "\n";
                }
            updatebooking:
                std::cout << "\nEnter booking number you would like to update: ";
                int index;
                std::cin >> index;
                if (index < 1 || index > bookingCount) {
                    std::cout << "Invalid booking number.\n";
                    system("pause");
                    continue;
                }
                index--;

                std::cout << "\nEnter your new pickup location:\n";
                std::cout << "1. DPulzeMallX \n2. Apple Store \n3. Mamak Power\n4. IoI Mall";
                std::cout << "\nSelect option: ";
                std::cin >> pickup;


                std::cout << "\n\nEnter your new dropoff location:\n";
                std::cout << "1. DPulzeMallX \n2. Apple Store \n3. Mamak Power\n4. IoI Mall";
                std::cout << "\nSelect option: ";
                std::cin >> dropoff;

                if (pickup == dropoff) {
                    std::cout << "\nPickup and DropOff cannot be the same location. Please Try Again\n";
                    system("pause");
                    goto updatebooking;
                }

                std::cout << "\n\nEnter your new pickup time:\n";
                std::cout << "1. 4.00 p.m. \n2. 5.00 p.m. \n3. 6.00 p.m.";
                std::cout << "\nSelect option: ";
                std::cin >> timechoice;

                float fare = calculateFare(pickup, dropoff);

                std::cout << "\n\nYou Have Made A Booking To PickUp From: "
                    << locations[pickup]
                    << " And DropOff At: "
                    << locations[dropoff]
                    << " At: "
                    << times[timechoice]
                    << "\n";

                std::cout << "Total Fare: RM " << std::fixed << std::setprecision(2) << fare << "\n";

                std::cout << "Please Confirm Your New Updated Booking By Entering (y/Y): ";

                char confirm;
                std::cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    bookings[index] = { locations[pickup], locations[dropoff], times[timechoice], fare };

                    std::cout << "\n\nBooking updated!\n";
                }
                else if (choice2 == 3) {
                system("cls");
                std::cout << "Your Bookings\n";
                if (bookingCount == 0) {
                    std::cout << "No bookings yet.\n";
                }
                else {
                    for (int i = 0; i < bookingCount; i++) {
                        std::cout << i + 1 << ". From " << bookings[i].pickup
                            << " To " << bookings[i].dropoff
                            << " At " << bookings[i].time 
                            << " Fare: RM " << std::fixed << std::setprecision(2) << bookings[i].fare << "\n";

                    }
                }
            }

            else if (choice2 == 4) {
                system("cls");
                if (bookingCount == 0) {
                    std::cout << "No bookings to delete.\n";
                    system("pause");
                    continue;
                }
                std::cout << "Delete Booking\n";
                for (int i = 0; i < bookingCount; i++) {
                    std::cout << i + 1 << ". From " << bookings[i].pickup
                        << " To " << bookings[i].dropoff
                        << " At " << bookings[i].time
                        << " Fare: RM " << std::fixed << std::setprecision(2) << bookings[i].fare << "\n";
                }
                std::cout << "\nEnter the booking's number you would like to delete: ";
                int index;
                std::cin >> index;
                if (index < 1 || index > bookingCount) {
                    std::cout << "Invalid booking number.\n";
                    system("pause");
                    continue;
                }
                index--;
                for (int i = index; i < bookingCount - 1; i++) {
                    bookings[i] = bookings[i + 1];
                }
                bookingCount--;
                std::cout << "Booking deleted!\n";
            }


            }
