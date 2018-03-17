#include <iostream>
#include <fstream>
#include <string>
#include "videoType.h"
#include "videoListType.h"

using namespace std;

void createVideoList(ifstream& infile, videoListType& videoList);
void displayMenu();

int main()
{
    videoListType videoList;
    int choice;
    char ch;
    string title;
    ifstream infile;

    infile.open('videoDat.txt');
    if (!infile) {
        cout << "The input file does not exist. The program terminates!!!" << endl;
        return 1;
    }

    createVideoList(infile, videoList);
    infile.close();

    displayMenu();
    cout << "Enter your choice: ";
    cin >> choice;
    cin.get(ch);
    cout << endl;

    while (choice != 9) {
        switch (choice) {
            case  1:
                cout << "Enter the title: ";
                getline(cin, title);
                cout << endl;

                if (videoList.videoSearch(title))
                    cout << "The store carries " << title << endl;
                else cout << "The store does not carry " << title << endl;
                break;

            case 2:
                cout << "Enter the title: ";
                getline(cin, title);
                cout << endl;

                if (videoList.videoSearch(title)) {
                    if (videoList.isVideoAvailable(title)) {
                        videoList.videoCheckOut(title);
                        cout << "Enjoy your movie: " << title << endl;
                    } else cout << "Currently " << title << " is out of stock." << endl;
                } else cout << "The store does not carry " << title << endl;
                break;

            case 3:
                cout << "Enter the title: ";
                getline(cin, title);
                cout << endl;

                if (videoList.videoSearch(title)) {
                    videoList.videoCheckIn(title);
                    cout << "Thanks for returning " << title << endl;
                } else cout << "The store does not carry " << title << endl;
                break;

            case 4:
                cout << "Enter the title: ";
                getline(cin, title);
                cout << endl;

                if (videoList.videoSearch(title)) {
                    if (videoList.isVideoAvailable(title))
                        cout << title << " is Currently in stock." << endl;
                    else cout << title << " is Currently out of stock." << endl;
                } else cout << "The store does not carry " << title << endl;
                break;

            case 5:
                videoList.videoPrintTitle();
                break;
            case 6:
                videoList.print();
                break;
            default: cout << "Invalid selection." << endl;
        }

        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;
        cin.get(ch);
        cout << endl;
    }
}

void createVideoList(ifstream& infile, videoListType videoList)
{
    string title;
    string star1;
    string star2;
    string producer;
    string director;
    string productionCo;
    char ch;
    int inStock;

    videoType newVideo;
    getline(infile, title);

    while (infile) {
        getline(infile, star1);
        getline(infile, star2);
        getline(infile, producer);
        getline(infile, director);
        getline(infile, productionCo);
        infile >> inStock;
        infile.get(ch);

        newVideo.setVideoInfo(title, star1, star2, producer, director, productionCo, inStock);
        videoList.insertFirst(newVideo);
        getline(infile, title);
    }
}

void displayMenu()
{
    cout << "Select one of the following:" << endl;
    cout << "1: To check whether the store carries a particular video." << endl;
    cout << "2: To check out a video." << endl;
    cout << "3: To check in a video." << endl;
    cout << "4: To check whether a particular video is in stock." << endl;
    cout << "5: To print only the titles of all the videos." << endl;
    cout << "6: To print a list of all the videos" << endl;
    cout << "9: To exit" << endl; 
}
