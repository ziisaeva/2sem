#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Структура для хранения информации о фильме
struct Movie {
    string title;
    string director;
    string genre;
    int duration;
    int showTime;
};

// Функции для работы с базой данных
void loadFromFile(vector<Movie>& movies, string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Movie movie;
        getline(ss, movie.title, ',');
        getline(ss, movie.director, ',');
        getline(ss, movie.genre, ',');
        ss >> movie.duration;
        ss.ignore();
        ss >> movie.showTime;
        movies.push_back(movie);
    }
    file.close();
}

void saveToFile(vector<Movie>& movies, string filename) {
    ofstream file(filename);
    for (const auto& movie : movies) {
        file << movie.title << "," << movie.director << "," << movie.genre << "," << movie.duration << "," << movie.showTime << endl;
    }
    file.close();
}

void addMovie(vector<Movie>& movies) {
    Movie movie;
    cout << "Enter title: ";
    cin >> movie.title;
    cout << "Enter director: ";
    cin >> movie.director;
    cout << "Enter genre: ";
    cin >> movie.genre;
    cout << "Enter duration (in minutes): ";
    cin >> movie.duration;
    cout << "Enter show time (in 24-hour format): ";
    cin >> movie.showTime;
    movies.push_back(movie);
}

void editMovie(vector<Movie>& movies) {
    int index;
    cout << "Enter the index of the movie to edit: ";
    cin >> index;
    if (index >= 0 && index < movies.size()) {
        cout << "Enter new title: ";
        cin >> movies[index].title;
        cout << "Enter new director: ";
        cin >> movies[index].director;
        cout << "Enter new genre: ";
        cin >> movies[index].genre;
        cout << "Enter new duration (in minutes): ";
        cin >> movies[index].duration;
        cout << "Enter new show time (in 24-hour format): ";
        cin >> movies[index].showTime;
    } else {
        cout << "Invalid index." << endl;
    }
}

void deleteMovie(vector<Movie>& movies) {
    int index;
    cout << "Enter the index of the movie to delete: ";
    cin >> index;
    if (index >= 0 && index < movies.size()) {
        movies.erase(movies.begin() + index);
    } else {
        cout << "Invalid index." << endl;
    }
}

void searchMovies(vector<Movie>& movies) {
    string title;
    cout << "Enter the title of the movie to search: ";
    cin >> title;
    for (const auto& movie : movies) {
        if (movie.title == title) {
            cout << "Title: " << movie.title << ", Director: " << movie.director << ", Genre: " << movie.genre << ", Duration: " << movie.duration << " minutes, Show Time: " << movie.showTime << endl;
        }
    }
}

int main() {
    vector<Movie> movies;
    string filename = "movies.txt";
    loadFromFile(movies, filename);

    while (true) {
        cout << "1. Add movie" << endl;
        cout << "2. Edit movie" << endl;
        cout << "3. Delete movie" << endl;
        cout << "4. Search movies" << endl;
        cout << "5. Save and exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addMovie(movies);
                break;
            case 2:
                editMovie(movies);
                break;
            case 3:
                deleteMovie(movies);
                break;
            case 4:
                searchMovies(movies);
                break;
            case 5:
                saveToFile(movies, filename);
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}
