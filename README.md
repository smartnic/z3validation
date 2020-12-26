# Z3 Validation

An approach to validating using z3 solver.

## About

In an effort to reduce validation time of z3 formulas, the best of two random seeded server approach was utilized. In this approach, the z3 formula is sent to both servers, each set with a different seed, and if:
a) both servers return within a couple of microseconds of each other it will read output and continue
b) if either server returns first (by a signifcant margin), the other server is killed and restarted and the formula from the returned server is read.

Through this approach, the longer validation times were able to be reduced.

## How to Execute

1. Make sure z3 dependencies are installed (more in https://github.com/Z3Prover/z3)

```
git clone https://github.com/Z3Prover/z3.git
cd z3
git checkout 1c7d27bdf31ca038f7beee28c41aa7dbba1407dd
python scripts/mk_make.py
cd build
make
sudo make install
```

2. Clone repository and compile

```
git clone https://github.com/smartnic/z3validation.git
cd z3validation
make
```

3. Run ./main.out [iterations]

```
./main.out 10
```

4. Clean Environment

```
pkill z3server.out
```
