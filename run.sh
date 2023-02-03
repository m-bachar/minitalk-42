#!/bin/bash

rm client
rm server
cc client.c mandatory_utils.c ./ft_printf/libftprintf.a -o client
cc server.c mandatory_utils.c ./ft_printf/libftprintf.a -o server
