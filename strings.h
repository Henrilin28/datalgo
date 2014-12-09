//
//  strings.h
//  datalgo
//
//  Created by Iyed Bennour on 11/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#ifndef __datalgo__strings__
#define __datalgo__strings__

#include <stdio.h>
#include <string>

bool str_in_str(const char *str1, const char *str2);
void reverse_string(std::string& s);
char find_first_non_repeating_char(const std::string& s);

bool test_find_first_non_repeating_char();
bool test_string_in_string();
bool test_revers_string();

#endif /* defined(__datalgo__strings__) */
