#include <iostream>

using namespace std;

#include "FC.h"

FC::FC()
{
    size = 0;
    noOfFilms = 0;
    films = NULL;
}

FC::FC( const FC &fcToCopy)
    :size( fcToCopy.size)
{
    if ( size > 0 )
    {
        films = new Film [ size ];
        for ( unsigned int i = 0; i < size; i++ )
            films[ i ] = fcToCopy.films[ i ];
    }
    else
        films = NULL;
}

FC::~FC()
{
    if ( films)
        delete [] films;
}

void FC::operator=( const FC &right)
{
    if ( &right != this )
    {
        if ( size != right.size )
        {
            if ( size > 0 )
                delete [] films;
            size = right.size;
            if ( size > 0 )
                films = new Film[ size ];
            else
                films = NULL;
        }
    for ( unsigned int i = 0; i < size; i++ )
        films[ i ] = right.films[ i ];
    }
}

bool FC::addFilm( const string fTitle, const string fDirector,
                const unsigned int fYear, const unsigned int fDuration)
{
    if( !films)
    {
        size++;
        noOfFilms++;

        films = new Film[size];
        Film *f = new Film( fTitle, fDirector, fYear, fDuration);

        films[0] = *f;

        return true;
    }
    else
    {
        Film *temp = films;
        bool found = false;

        for( unsigned int i = 0; i < size; i++)
        {
            if ( films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector )
            {
                found = true;
            }
        }

        if ( !found)
        {
            size++;

            films = new Film[size];
            Film* f1 = new Film( fTitle, fDirector, fYear, fDuration);
            films[ size - 1] = *f1;
            noOfFilms ++;

            for ( unsigned int i = 0 ; i < size - 1; i++)
            {
                films[i] = temp[i];
            }

            delete [] temp;

            return true;
        }
        return false;
    }
}

bool FC::removeFilm( const string fTitle, const string fDirector)
{
    if ( !films)
	 {
		 return false;
	 }
	 else
	 {
		 bool found = false;
		 int index;
		 Film *temp = films;

		 index = -1;

		 for( unsigned int i = 0; i < size; i++)
		 {
			if ( films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector )
			{
				index = i;
				found = true;
			}
		 }

		 if ( found)
		 {
			 size--;
			 films = new Film[size];
			 noOfFilms--;
			 int count = 0;

			 for ( unsigned int i = 0; i < size + 1; i++)
			 {
				 if ( i != index)
				 {
                    films[count] = temp[i];
					count++;
				 }
			 }
			 delete [] temp;

			 return true;
		 }
		 else
			return false;
	 }
}

 unsigned int FC::getFilms(Film *&allFilms) const
 {
     allFilms = new Film[noOfFilms];

     for ( unsigned int i = 0; i < noOfFilms; i++)
     {
         allFilms[i] = films[i];
     }
     return noOfFilms;
 }

 bool FC::addActor( const string fTitle, const string fDirector,
                    const string aName, const string aBirthPlace,
                    const unsigned int aBirthYear)
{
    if ( !films)
    {
        return false;
    }

    else
    {
        bool found = false;
        int index = -1;

        for( unsigned int i = 0; i < size; i++)
        {
            if ( films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector )
            {
                index = i;
                found = true;
            }
        }

        if ( found)
        {
            Actor a( aName, aBirthPlace, aBirthYear);
            films[index].addNewActor( a);

            return true;
        }
        return false;
    }

}

bool FC::removeActors( const string fTitle, const string fDirector)
{
    if ( !films)
        return false;
    else
    {
        bool found = false;
        int index = -1;

        for( unsigned int i = 0; i < size; i++)
        {
            if ( films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector )
            {
                index = i;
                found = true;
            }
        }

        if ( found)
        {
            films[index].removeAllActors();
            return true;
        }
        return false;
    }
}

unsigned int FC::calculateAverageDuration() const
{
    if ( !films)
    {
        return 0;
    }

    else
    {
        int sum = 0;
        for ( int i = 0; i < size; i++)
            sum = sum + films[i].getFilmDuration();
        return sum / noOfFilms;
    }
}




