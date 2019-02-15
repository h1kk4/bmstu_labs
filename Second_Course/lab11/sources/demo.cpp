#include <iostream>
#include <boost/program_options.hpp>
#include <print.hpp>
#include <cstdlib>

namespace po = boost::program_options;

void print_file(const std::string &path) {
    std::string label;
    while (std::cin >> label) {
        std::ofstream out(path, std::ios_base::app);
        print(label, out);
        out << std::endl;
    }
}

int main(int argc, char **argv) {
    std::string path_file;
    std::string name;
    po::options_description desc("Allowed options");
    desc.add_options()
            ("output", po::value<std::string>(), "set name to logfile")
            ("variable", po::value<std::string>(&path_file))
            ("name", po::value<std::string>(&name), "from config file");

    po::variables_map vm;
    std::string path = std::getenv("HOME");
    path += "/.config/demo.cfg";
    std::ifstream configfile(path);
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::store(po::parse_environment(desc,
                                    [](const std::string &env_var) {
                                        return env_var == "DEMO_OUTPUT" ? "variable" : "";
                                    }), vm);
    po::store(po::parse_config_file(configfile, desc), vm);
    po::notify(vm);

    if (vm.count("output")) {
        print_file(vm["output"].as<std::string>());
    } else if (!path_file.empty()) {
        print_file(path_file);
    } else if (!name.empty()) {
        print_file(name);
    } else {
        print_file("default.log");
    }
    configfile.close();
    return 0;
}