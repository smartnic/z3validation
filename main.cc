#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "z3client.h"
using namespace z3;

void example_one(int iter){
    context c;
    model mdl(c);
    expr x = c.int_const("x");
    expr y = c.int_const("y");
    solver s(c);
    s.add(x >= 1);
    s.add(y < x + 3);

    int count = 1;
    while (count <= iter){
      /* We've received a serialized version of a Z3 model. Extract a
      * model object from this. */
      string res = write_problem_to_z3server(s.to_smt2()); 
      std::cout << "Iteration #" << count << ":" << endl;
      if (res.compare(0, 1, "(") == 0) {
        solver s1(c);
        s1.from_string(res.c_str());
        auto is_sat = s1.check();
        assert (is_sat == z3::sat);
        mdl = s1.get_model();
        /** Print model **/
        for (unsigned i = 0; i < mdl.size(); i++) {
            func_decl v = mdl[i];
            std::cout << v.name() << " = " << mdl.get_const_interp(v) << "\n";
        }
      } else {
        cout << "z3 solver client received unexpected output: '"
            << res << "'\n";
      }

      count++; // increase loop count
    }
}


int main(int argc, char* argv[]) {
    cout << "Sample use of z3Validation\n";
    int iter = 10;
    if (argc == 2)
    {
      iter = std::stoi(argv[1]);
    }
    example_one(iter);
}