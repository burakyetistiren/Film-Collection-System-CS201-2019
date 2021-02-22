#ifndef __FILM_H
#define __FILM_H

#include "Actor.h"

class Film{
    public:
        Film(const string fTitle = "", const string fDirector = "",
             const unsigned int fYear = 0,
             const unsigned int fDuration = 0);
        Film(const Film &fToCopy);
        ~Film();
        void operator=(const Film &right);
        void setNoOfActors( int i);
        void addNewActor( Actor &a);
        void removeAllActors();
        string getFilmTitle() const;
        string getFilmDirector() const;
        Actor* getActors() const;
        unsigned int getNoOfActors() const;
        unsigned int getFilmYear() const;
        unsigned int getFilmDuration() const;
        unsigned int calculateAverageActorAge() const;

        friend ostream& operator<<(ostream& out, const Film& f);

    private:
        Actor *actors;
        string title;
        string director;
        unsigned int year;
        unsigned int duration;
        unsigned int noOfActors;
        unsigned int size;
};
#endif
