#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include <colorize/color.hpp>

int main() {
  // { Nothing = 0, Minute, Hour, To, Past, Am, Pm };
  enum class Type {
    Min,
    Hour,
    Past,
    To,

  };
  struct Coordinates {
    size_t begin = 0, end = 0;
    bool highlight = false;
  };
  // clang-format off
  const std::vector<std::string> screen{
    "ITLISASAMPM",
    "ACQUARTERDC",
    "TWENTYFIVEX",
    "HALFSTENFT0",
    "PASTERUNINE",
    "0NESIXTHREE",
    "FOURFIVETWO",
    "EIGHTELEVEN",
    "SEVENTWELVE",
    "TENSE0CLOCK"
  };
  // clang-format on

  auto time = std::time(0);
  auto now = std::localtime(&time);

  auto past = now->tm_min < 35;
  auto hour = (now->tm_hour % 12) + (past ? 0 : 1);
  auto min = abs((past ? 0 : 60) - (now->tm_min - now->tm_min % 5));
  auto rest = now->tm_min % 5;

  std::cout << "past " << past << " hour " << hour << " min " << min << " rest " << rest << std::endl;

  /* struct Data {
    enum class Type { Nothing = 0, Minute, Hour, To, Past, Am, Pm };
    std::string text;
    bool highlight = false;
    uint8_t value = 0;
    uint8_t alt = 0;
    Type type = Type::Nothing;

    Data(const std::string text, const bool& hl = false, const Type& type = Type::Nothing, const uint8_t& value = 0,
         const uint8_t& alt = 0)
        : text(text)
        , highlight(hl)
        , value(value)
        , alt(alt)
        , type(type) {
    }
  };
  // clang-format off
  const std::vector<Data> words{
    {"IT", true}, {"L"}, {"IS", true}, {"AS"}, {"AM", false, Data::Type::Am}, {"PM", false, Data::Type::Pm}, {"\n"},
    {"A", false, Data::Type::Minute, 15}, {"C"}, {"QUARTER", false, Data::Type::Minute, 15}, {"DC"}, {"\n"},
    {"TWENTY", false, Data::Type::Minute, 20, 25}, {"FIVE", false, Data::Type::Minute, 5, 25}, {"X"}, {"\n"},
    {"HALF", false, Data::Type::Minute, 30}, {"S"}, {"TEN", false, Data::Type::Minute, 10}, {"F"}, {"T0", false,
  Data::Type::To}, {"\n"},
    {"PAST", false, Data::Type::Past}, {"ERU"}, {"NINE", false, Data::Type::Hour, 9}, {"\n"},
    {"0NE", false, Data::Type::Hour, 1}, {"SIX", false, Data::Type::Hour, 6}, {"THREE", false, Data::Type::Hour, 3},
  {"\n"},
    {"FOUR", false, Data::Type::Hour, 4}, {"FIVE", false, Data::Type::Hour, 5}, {"TWO", false, Data::Type::Hour, 2},
  {"\n"},
    {"EIGHT", false, Data::Type::Hour, 8}, {"ELEVEN", false, Data::Type::Hour, 11}, {"\n"},
    {"SEVEN", false, Data::Type::Hour, 7}, {"TWELVE", false, Data::Type::Hour, 12}, {"\n"},
    {"TEN", false, Data::Type::Hour, 10}, {"SE"}, {"0CLOCK", false, Data::Type::Minute, 0}, {"\n"}
  };
  // clang-format on

  auto time = std::time(0);
  auto now = std::localtime(&time);

  auto pastOrTo = now->tm_min < 35 ? Data::Type::Past : Data::Type::To;
  auto hour = (now->tm_hour % 12) + (pastOrTo == Data::Type::To ? 1 : 0);
  auto min = abs((pastOrTo == Data::Type::To ? 60 : 0) - (now->tm_min - now->tm_min % 5));
  auto rest = now->tm_min % 5;

  std::cout << color::rize(".", "Default", "Default", rest >= 1 ? "Bold" : "Dim");
  std::cout << color::rize("                     .", "Default", "Default", rest >= 2 ? "Bold" : "Dim") << std::endl;
  for (const auto& word : words) {
    for (size_t i = 0; i < word.text.size(); ++i) {
      // todo am/pm
      bool highlight = word.highlight || (word.type == Data::Type::Hour && word.value == hour) ||
                       (word.type == Data::Type::Minute && (word.value == min || word.alt == min)) ||
                       (word.type == pastOrTo && min != 0);

      std::cout << " "
                << color::rize(std::string() + word.text[i], highlight ? "White" : "Black", "Default",
                               highlight ? "Bold" : "Dim");
    }
  }
  std::cout << color::rize(".", "Default", "Default", rest >= 3 ? "Bold" : "Dim");
  std::cout << color::rize("                     .", "Default", "Default", rest >= 4 ? "Bold" : "Dim") << std::endl
            << std::endl;
*/
  return 0;
}
