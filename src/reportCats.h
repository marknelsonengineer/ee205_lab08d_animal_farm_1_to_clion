///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "catDatabase.h"

/// Print a cat.
/// @returns true if everything worked correctly.  false if something went
///          wrong (usually the index is invalid)
extern bool   printCat( const size_t index ) ;

/// Print all cats in the database
extern void   printAllCats() ;

extern size_t findCatByName( const char* name ) ;  ///< @returns the index or BAD_CAT
extern size_t findCatByCollars( enum Color collarColor1, enum Color collarColor2 ) ;  ///< @returns the index or BAD_CAT
extern size_t findCatByLicense( unsigned long long license ) ;  ///< @returns the index or BAD_CAT

/// Return a string for the name of the gender
extern const char* genderName( enum Gender gender ) ;

/// Return a string for the name of the breed
extern const char* breedName( enum Breed breed ) ;

/// Return a string for the name of the color
extern const char* colorName ( enum Color color ) ;
