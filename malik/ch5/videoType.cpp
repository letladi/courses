#include "videoType.h"

void videoType::setVideoInfo(string title, string star1, string star2, string producer, string director, string productionCo, int setInStock)
{
    videoTitle = title;
    movieStart1 = star1;
    movieStart2 = star2;
    movieProducer = producer;
    movieDirector = director;
    movieProductionCo = productionCo;
    copiesInStock = setInStock;
}

void videoType::checkOut()
{
    if (getNoOfCopiesInStock() > 0) copiesInStock--;
    else cout << "Currently out of stock" << endl;
}

void videoType::checkIn()
{
    copiesInStock++;
}

int videoType::getNoOfCopiesInStock() const
{
    return copiesInStock;
}

void videoType::printTitle() const
{
    cout << "Video Title: " << videoTitle << endl;
}

void videoType::printInfo() const
{
    cout << "Video Title: " << videoTitle << endl;
    cout << "Stars: " << movieStart1 << " and " << movieStart2 << endl;
    cout << "Producer: " << movieProducer << endl;
    cout << "Director: " << movieDirector << endl;
    cout << "Production Company: " << movieProductionCo << endl;
    cout << "Copies in stock: " << copiesInStock << endl;
}

bool videoType::checkTitle(string title)
{
    return videoTitle == title;
}

void videoType::updateInStock(int num)
{
    copiesInStock += num;
}

void videoType::setCopiesInStock(int num)
{
    copiesInStock = num;
}

string videoType::getTitle() const
{
    return videoTitle;
}

videoType::videoType(string title, string star1, string star2, string producer,
    string director, string productionCo, int setInStock)
{
    setVideoInfo(title, star1, star2, producer, director, productionCo, setInStock);
}

bool videoType::operator==(const videoType& other) const
{
    return videoTitle == other.videoTitle;
}

bool videoType::operator!=(const videoType& other) const
{
    return videoTitle != other.videoTitle;
}

ostream& operator<<(ostream& os, const videoType& video)
{
    os << endl;
    os << "Video Title: " << video.videoTitle << endl;
    os << "Stars: " << video.movieStart1 << " and " << video.movieStart2 << endl;
    os << "Producer: " << video.movieProducer << endl;
    os << "Director: " << video.movieDirector << endl;
    os << "Production Company: " << video.movieProductionCo << endl;
    os << "Copies in stock: " << video.copiesInStock << endl;
    os << "_______________________________________________" << endl;
    return os;
}
