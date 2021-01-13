/*
* Various string utils and parsing functions
* (C) 1999-2007,2013 Jack Lloyd
*
* Botan is released under the Simplified BSD License (see license.txt)
*/

#ifndef BOTAN_PARSING_UTILS_H_
#define BOTAN_PARSING_UTILS_H_

#include <botan/types.h>
#include <string>
#include <vector>
#include <istream>
#include <map>

namespace Botan {

/**
* Parse a SCAN-style algorithm name
* @param scan_name the name
* @return the name components
*/
std::vector<std::string>
parse_algorithm_name(const std::string& scan_name);

/**
* Split a string
* @param str the input string
* @param delim the delimitor
* @return string split by delim
*/
BOTAN_TEST_API std::vector<std::string> split_on(
   const std::string& str, char delim);

/**
* Join a string
* @param strs strings to join
* @param delim the delimitor
* @return string joined by delim
*/
std::string string_join(const std::vector<std::string>& strs,
                        char delim);

/**
* Convert a string to a number
* @param str the string to convert
* @return number value of the string
*/
BOTAN_TEST_API uint32_t to_u32bit(const std::string& str);

/**
* Convert a string to a number
* @param str the string to convert
* @return number value of the string
*/
uint16_t to_uint16(const std::string& str);

/**
* Convert a string representation of an IPv4 address to a number
* @param ip_str the string representation
* @return integer IPv4 address
*/
uint32_t string_to_ipv4(const std::string& ip_str);

/**
* Convert an IPv4 address to a string
* @param ip_addr the IPv4 address to convert
* @return string representation of the IPv4 address
*/
std::string ipv4_to_string(uint32_t ip_addr);

std::map<std::string, std::string> read_cfg(std::istream& is);

/**
* Accepts key value pairs deliminated by commas:
*
* "" (returns empty map)
* "K=V" (returns map {'K': 'V'})
* "K1=V1,K2=V2"
* "K1=V1,K2=V2,K3=V3"
* "K1=V1,K2=V2,K3=a_value\,with\,commas_and_\=equals"
*
* Values may be empty, keys must be non-empty and unique. Duplicate
* keys cause an exception.
*
* Within both key and value, comma and equals can be escaped with
* backslash. Backslash can also be escaped.
*/
BOTAN_TEST_API
std::map<std::string, std::string> read_kv(const std::string& kv);

std::string clean_ws(const std::string& s);

/**
* Check if the given hostname is a match for the specified wildcard
*/
BOTAN_TEST_API
bool host_wildcard_match(const std::string& wildcard,
                         const std::string& host);


}

#endif
