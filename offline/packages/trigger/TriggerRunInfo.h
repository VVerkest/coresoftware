#ifndef __TRIGGERRUNINFO_H__
#define __TRIGGERRUNINFO_H__

#include <phool/PHObject.h>

#include <iostream>
#include <string>
#include <array>
#include <cstdint>

class TriggerRunInfo  : public PHObject
{
public:
  TriggerRunInfo() = default;
  ///
  virtual ~TriggerRunInfo() override = default;

  void identify(std::ostream& os = std::cout) const override;

  virtual void setTrigger(int , const std::string&, int, int)  {return;}

  virtual int getPrescaleByName(const std::string&) const {return 0;}       


 private:  // so the ClassDef does not show up with doc++
  ClassDefOverride(TriggerRunInfo, 1);

};

#endif
