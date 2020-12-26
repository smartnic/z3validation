#pragma once

#include "z3++.h"
using namespace std;
extern int SERVER_PORT;
int spawn_server();
string write_problem_to_z3server(string formula);
int create_and_connect_socket(int port);
void send_formula(int sock, string formula);
void read_from_solver(int sock);
int poll_servers(int sock, int timeout);
string write_problem_to_z3server(string formula);