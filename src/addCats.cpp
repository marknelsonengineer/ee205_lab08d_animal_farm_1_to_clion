///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstring>   // For strcpy
#include <cstdio>
#include <cassert>

#include "config.h"
#include "catDatabase.h"
#include "reportCats.h"


/// Scan the database looking for the cat.  If it's there, return true.
bool isCatInDatabase( const char* name ) {
   for( size_t i = 0 ; i < numCats ; i++ ) {
      if( strncmp( cats[i].name, name, MAX_CAT_NAME ) == 0 ) {
         return true ;
      }
   }

   return false ;  // The cat's name wasn't found
}


/// Add a cat to the database
///
/// @returns The index to the cat --or-- BAD_CAT if there's a problem.
unsigned int addCat( const char*              name
        ,const enum Gender        gender
        ,const enum Breed         breed
        ,const bool               isFixed
        ,const float              weight
        ,const enum Color         collarColor1
        ,const enum Color         collarColor2
        ,const unsigned long long license
) {
   // Validate preconditions

   if( isFull() ) {  // The database is full
      return BAD_CAT ;
   }

   if( !isNameValid( name ) ) {
      return BAD_CAT ;
   }

   if( isCatInDatabase( name ) ) {
      fprintf( stderr, "%s: Cat name [%s] is already in the database.\n", PROGRAM_NAME, name ) ;
      return BAD_CAT ;
   }

   if( !isWeightValid( weight ) ) {
      return BAD_CAT ;
   }

   if( !areCatCollarsValid( collarColor1, collarColor2 )) {
      return BAD_CAT ;
   }

   if( findCatByLicense( license ) != BAD_CAT ) {
      return BAD_CAT ;
   }

   assert( validateDatabase() == true ) ;  // Verify the database is healthy before we tinker with it

   // Everything looks good, so add the cat

   size_t catIndex = numCats ;

   strncpy( cats[catIndex].name, name, MAX_CAT_NAME ) ;
   cats[catIndex].gender       = gender  ;
   cats[catIndex].breed        = breed   ;
   cats[catIndex].isFixed      = isFixed ;
   cats[catIndex].weight       = weight  ;
   cats[catIndex].collarColor1 = collarColor1 ;
   cats[catIndex].collarColor2 = collarColor2 ;
   cats[catIndex].license      = license      ;

#ifdef DEBUG
   printf( "%s: Added cat [%s] as [%lu]\n", PROGRAM_NAME, name, catIndex ) ;
#endif

   // Set postconditions
   numCats += 1 ;  // We've just added one cat to the database

   assert( validateDatabase() == true ) ;  // Verify the database is healthy
   // after we tinker with it

   return catIndex ;
}
