#include <iostream>

using namespace std;

#include "SimpleFC.h"

FC::FC()
{
   size = 0;
   noOfFilms = 0;
   films = NULL;
}

FC::FC( const FC &fcToCopy)
    :size( fcToCopy.size)
{
    if ( size > 0 ) {
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

void FC::operator=(const FC &right)
{
    if ( &right != this ) {
            if ( size != right.size ) {
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

bool FC::addFilm(const string fTitle, const string fDirector,
                 const unsigned int fYear,
                 const unsigned int fDuration)
{
    if ( !films)
    {
        size = 1;
        noOfFilms = 1;
        films = new Film[size];
        Film *fN = new Film( fTitle, fDirector, fYear, fDuration);

        films[0] = *fN;

		return true;
    }
    Film *temp = films;
    bool found = false;

    for( unsigned int i = 0; i < size; i++)
    {
        if ( films[i].getTitle() == fTitle && films[i].getDirector() == fDirector )
        {
            found = true;
        }
    }
    if ( !found)
    {
		size++;
        films = new Film[ size ];
        Film* f = new Film( fTitle, fDirector, fYear, fDuration);
        films[ size - 1] = *f;
        noOfFilms ++;

        for ( unsigned int j = 0; j < size - 1 ; j++)
        {
            films[j] = temp[j];
        }

		delete [] temp;

		return true;
	}
	else
		return false;
}

 bool FC::removeFilm(const string fTitle, const string fDirector)
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
			if ( films[i].getTitle() == fTitle && films[i].getDirector() == fDirector )
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
			 for ( unsigned int j = 0; j < size + 1; j++)
			 {
				 if ( j != index)
                 {
                    films[count] = temp[j];
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
         allFilms[i] = Film( films[i]);
     }
     return noOfFilms;
 }

