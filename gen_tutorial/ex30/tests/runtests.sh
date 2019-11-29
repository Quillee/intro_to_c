echo "Running tests:"

for i in tests/*_test
do
    if test -f $i
    then
        if VALGRIND ./$i 2>> tests/tests.log
        then
            echo $i PASS
        else
            echo "[ERROR] -- in test $i: check test/test.log"
            echo "-------------"
            echo "Tail of log:"
            tail tests/test.log
            echo "-------------"
            exit
        fi
    fi
    done
    echo ""