//
//  strings.h
//  interview
//
//  Created by Iyed Bennour on 11/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#ifndef __interview__strings__
#define __interview__strings__

#include <stdio.h>
#include <string>

bool str_in_str(const char *str1, const char *str2);
bool test_string_in_string();

void reverse_string(std::string& s);
bool test_revers_string();

char find_first_non_repeating_char(const std::string& s);
bool test_find_first_non_repeating_char();

#endif /* defined(__interview__strings__) */
