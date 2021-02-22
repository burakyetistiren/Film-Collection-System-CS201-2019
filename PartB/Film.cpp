#include <iostream>
#include <string>

using namespace std;

#include "Film.h"

Film::Film( const string fTitle, const string fDirector,
           const unsigned int fYear,
           const unsigned int fDuration)
{
    title = fTitle;
    director = fDirector;
    year = fYear;
    duration = fDuration;
    noOfActors = 0;

    actors = NULL;

    size = 0;
}

Film::Film( const Film &fToCopy)
{
    title = fToCopy.title;
    director = fToCopy.director;
    year = fToCopy.year;
    duration = fToCopy.duration;

    if ( actors)
        actors = fToCopy.actors;
    noOfActors = fToCopy.noOfActors;
    size = fToCopy.size;
}

Film::~Film()
{
    if ( actors)
        delete [] actors;
}

void Film::operator=(const Film &right)
 {
     title = right.title;
     director = right.director;
     year = right.year;
     noOfActors = right.noOfActors;
     duration = right.duration;
     size = right.size;

     actors = new Actor[noOfActors];
     for ( int i = 0; i < noOfActors; i++)
     {
         actors[i] = right.actors[i];
     }

 }

string Film::getFilmTitle() const
{
    return title;
}

string Film::getFilmDirector() const
{
    return director;
}

unsigned int Film::getFilmYear() const
{
    return year;
}

unsigned int Film::getFilmDuration() const
{
    return duration;
}

Actor* Film::getActors() const
{
    return actors;
}

unsigned int Film::calculateAverageActorAge() const
{
    double sum = 0;
    double average = 0;
    if ( actors)
    {
        for ( unsigned int i = 0; i < noOfActors; i++)
        {
            sum = sum + getFilmYear() - actors[i].getBirthYear();
        }

        average = sum / double( noOfActors);
    }

    return (int)average;
}
unsigned int Film::getNoOfActors() const
{
    return noOfActors;
}

void Film::setNoOfActors( int i)
{
    noOfActors = i;
}

void Film::addNewActor(Actor &a)
{
        Actor *temp;
        temp = actors;

        actors = new Actor[noOfActors + 1];

        for ( int i = 0; temp && i < noOfActors; i++)
            actors[i] = temp[i];

        actors[noOfActors] = a;
        noOfActors++;

        if(temp)
            delete [] temp;
}

void Film::removeAllActors()
{
    if(actors) { delete[] actors; actors = NULL; noOfActors = 0;}
}

ostream& operator<<(ostream& out, const Film& f)
{
    out << f.getFilmTitle() << ", "  << f.getFilmYear() << ", "
     <<  f.getFilmDirector() << ", " << f.getFilmDuration() << " min" <<
     endl;
     for ( unsigned int i = 0; i < f.noOfActors; i++)
     {
         out << f.actors[i] << endl;

     }

     return out;
}
