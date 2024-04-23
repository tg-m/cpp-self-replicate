#include <fstream>
#include <iostream>
#include <regex>

#include <cstdlib>


static std::string code = R"TAG(#include <fstream>
#include <iostream>
#include <regex>

#include <cstdlib>


// CODE_PLACEHOLDER


int main() {


    std::string const cxx_file_name = "/tmp/x.cc";
    std::string const run_file_name = "/tmp/x.run";

    {
        std::regex const re_code_placeholder{"// CODE_PLACEHOLDER"};
        std::string const cp_inject =
            std::string("static std::string code = R\"TAG(") + code +
            ")TAG\";";

        code = std::regex_replace(
            code,
            re_code_placeholder,
            cp_inject,
            std::regex_constants::format_first_only
        );
    }

    {
        std::ofstream file(cxx_file_name);

        file << code;
    }

    std::string const cmd_compile =
        "g++ " + cxx_file_name + " -o " + run_file_name;
    std::system(cmd_compile.c_str());
    std::system(run_file_name.c_str());

    return 0;
}
)TAG";


int main() {


    std::string const cxx_file_name = "/tmp/x.cc";
    std::string const run_file_name = "/tmp/x.run";

    {
        std::regex const re_code_placeholder{"// CODE_PLACEHOLDER"};
        std::string const cp_inject =
            std::string("static std::string code = R\"TAG(") + code +
            ")TAG\";";

        code = std::regex_replace(
            code,
            re_code_placeholder,
            cp_inject,
            std::regex_constants::format_first_only
        );
    }

    {
        std::ofstream file(cxx_file_name);

        file << code;
    }

    std::string const cmd_compile =
        "g++ " + cxx_file_name + " -o " + run_file_name;
    std::system(cmd_compile.c_str());
    std::system(run_file_name.c_str());

    return 0;
}
