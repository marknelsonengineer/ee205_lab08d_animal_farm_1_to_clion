///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <cstdlib>

/// Delete all of the cats in the database.
/// @returns true if the cats were successfully deleted.
///          false if something bad happened
extern bool deleteAllCats() ;

/// Delete a cat in the database.
/// @returns true if the cat was successfully deleted.
///          false if something bad happened
extern bool deleteCat( const size_t index ) ;
