// Copyright (c) 2013 Tencent Inc.
// Author: Lifeng Wang (fandywang@tencent.com)
//
// The Vocabulary class.

#ifndef MLTK_MAXENT_VOCABULARY_H_
#define MLTK_MAXENT_VOCABULARY_H_

#include <stdint.h>

#include <map>
#include <string>
#include <vector>

namespace mltk {
namespace maxent {

typedef std::map<std::string, int32_t> StringMapType;

class Vocabulary {
 public:
  Vocabulary() {}
  ~Vocabulary() {}

  int32_t Put(const std::string& s) {
    StringMapType::const_iterator citer = str2id_.find(s);
    if (citer == str2id_.end()) {
      int32_t id = static_cast<int32_t>(id2str_.size());
      id2str_.push_back(s);
      str2id_[s] = id;

      return id;
    }
    return citer->second;
  }

  int32_t Id(const std::string& s) const {
    StringMapType::const_iterator citer = str2id_.find(s);
    if (citer == str2id_.end())  return -1;
    return citer->second;
  }

  std::string Str(const int32_t id) const {
    assert(id >= 0 && id < static_cast<int32_t>(id2str_.size()));
    return id2str_[id];
  }

  size_t Size() const { return id2str_.size(); }

  void Clear() {
    str2id_.clear();
    id2str_.clear();
  }

  StringMapType::const_iterator begin() const { return str2id_.begin(); }
  StringMapType::const_iterator end() const { return str2id_.end(); }

 private:
  StringMapType str2id_;
  std::vector<std::string> id2str_;
};

}  // namespace maxent
}  // namespace mltk

#endif  // MLTK_MAXENT_VOCABULARY_H_

