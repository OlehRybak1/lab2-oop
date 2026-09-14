#include "Video.h"

Video::Video()
{
    title = "Unknown";
    theme = "Unknown";
    actors = "Unknown";
    rating = 0;
    length = 0;
    speed = 1.0;
    fileName = "unknown.mp4";
    date = "0000-00-00";
}

Video::Video(std::string title, std::string theme, std::string actors,
             double rating, double length, double speed,
             std::string fileName, std::string date)
{
    this->title = title;
    this->theme = theme;
    this->actors = actors;
    this->rating = rating;
    this->length = length;
    this->speed = speed;
    this->fileName = fileName;
    this->date = date;
}

Video::~Video()
{
}

std::string Video::getTitle() const { return title; }
void Video::setTitle(const std::string& value) { title = value; }

std::string Video::getTheme() const { return theme; }
void Video::setTheme(const std::string& value) { theme = value; }

std::string Video::getActors() const { return actors; }
void Video::setActors(const std::string& value) { actors = value; }

double Video::getRating() const { return rating; }
void Video::setRating(double value) { rating = value; }

double Video::getLength() const { return length; }
void Video::setLength(double value) { length = value; }

double Video::getSpeed() const { return speed; }
void Video::setSpeed(double value) { speed = value; }

std::string Video::getFileName() const { return fileName; }
void Video::setFileName(const std::string& value) { fileName = value; }

std::string Video::getDate() const { return date; }
void Video::setDate(const std::string& value) { date = value; }

// Пошук підрядка actorSubstr у списку акторів (без урахування регістру)
bool Video::hasActor(const std::string& actorSubstr) const
{
    auto toLower = [](std::string s)
    {
        for (auto& c : s) c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        return s;
    };
    return toLower(actors).find(toLower(actorSubstr)) != std::string::npos;
}
