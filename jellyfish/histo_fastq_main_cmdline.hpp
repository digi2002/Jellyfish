/***** This code was generated by Yaggo. Do not edit ******/

#ifndef __HISTO_FASTQ_MAIN_ARGS_HPP__
#define __HISTO_FASTQ_MAIN_ARGS_HPP__

#include <yaggo.hpp>

class histo_fastq_main_args {
public:
  double                         low_arg;
  bool                           low_given;
  double                         high_arg;
  bool                           high_given;
  double                         increment_arg;
  bool                           increment_given;
  bool                           full_flag;
  const char *                   db_arg;

  enum {
    USAGE_OPT = 1000,
    HELP_OPT
  };

  histo_fastq_main_args(int argc, char *argv[]) :
    low_arg(0.0), low_given(false),
    high_arg(10000.0), high_given(false),
    increment_arg(1.0), increment_given(false),
    full_flag(false)
  {
    static struct option long_options[] = {
      {"low", 1, 0, 'l'},
      {"high", 1, 0, 'h'},
      {"increment", 1, 0, 'i'},
      {"full", 0, 0, 'f'},
      {"help", 0, 0, HELP_OPT},
      {"usage", 0, 0, USAGE_OPT},
      {"version", 0, 0, 'V'},
      {0, 0, 0, 0}
    };
    static const char *short_options = "Vl:h:i:f";

    std::string err;
#define CHECK_ERR(type,val,which) if(!err.empty()) { std::cerr << "Invalid " #type " '" << val << "' for [" which "]: " << err << "\n"; exit(1); }
    while(true) { 
      int index = -1;
      int c = getopt_long(argc, argv, short_options, long_options, &index);
      if(c == -1) break;
      switch(c) {
      case ':': 
        std::cerr << "Missing required argument for "
                  << (index == -1 ? std::string(1, (char)optopt) : std::string(long_options[index].name))
                  << std::endl;
        exit(1);
      case HELP_OPT:
        std::cout << usage() << "\n\n" << help() << std::endl;
        exit(0);
      case USAGE_OPT:
        std::cout << usage() << "\nUse --help for more information." << std::endl;
        exit(0);
      case 'V':
        print_version();
        exit(0);
      case '?':
        std::cerr << "Use --usage or --help for some help\n";
        exit(1);
      case 'l':
        low_given = true;
        low_arg = yaggo::conv_double((const char *)optarg, err, false);
        CHECK_ERR(double_t, optarg, "-l, --low=double")
        break;
      case 'h':
        high_given = true;
        high_arg = yaggo::conv_double((const char *)optarg, err, false);
        CHECK_ERR(double_t, optarg, "-h, --high=double")
        break;
      case 'i':
        increment_given = true;
        increment_arg = yaggo::conv_double((const char *)optarg, err, false);
        CHECK_ERR(double_t, optarg, "-i, --increment=double")
        break;
      case 'f':
        full_flag = true;
        break;
      }
    }
    if(argc - optind != 1)
      error("Requires exactly 1 argument.");
    db_arg = argv[optind];
    ++optind;
  }
#define histo_fastq_main_args_USAGE "Usage: jellyfish qhisto [options] db:c_string"
  const char * usage() const { return histo_fastq_main_args_USAGE; }
  void error(const char *msg) { 
    std::cerr << "Error: " << msg << "\n" << usage()
              << "\nUse --help for more information"
              << std::endl;
    exit(1);
  }
#define histo_fastq_main_args_HELP "Create an histogram of k-mer occurences\n\n" \
  "Options (default value in (), *required):\n" \
  " -l, --low=double                         Low count value of histogram (0.0)\n" \
  " -h, --high=double                        High count value of histogram (10000.0)\n" \
  " -i, --increment=double                   Increment value for buckets (1.0)\n" \
  " -f, --full                               Full histo. Don't skip count 0. (false)\n" \
  "     --usage                              Usage\n" \
  "     --help                               This message\n" \
  " -V, --version                            Version"

  const char * help() const { return histo_fastq_main_args_HELP; }
#define histo_fastq_main_args_HIDDEN "Hidden options:"

  const char * hidden() const { return histo_fastq_main_args_HIDDEN; }
  void print_version(std::ostream &os = std::cout) const {
#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION "0.0.0"
#endif
    os << PACKAGE_VERSION << "\n";
  }
  void dump(std::ostream &os = std::cout) {
    os << "low_given:" << low_given << " low_arg:" << low_arg << "\n";
    os << "high_given:" << high_given << " high_arg:" << high_arg << "\n";
    os << "increment_given:" << increment_given << " increment_arg:" << increment_arg << "\n";
    os << "full_flag:" << full_flag << "\n";
    os << "db_arg:" << db_arg << "\n";
  }
private:
};

#endif // __HISTO_FASTQ_MAIN_ARGS_HPP__"
