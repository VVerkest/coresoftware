#ifndef FUN4ALLRAW_SINGLEZDCTRIGGERINPUT_H
#define FUN4ALLRAW_SINGLEZDCTRIGGERINPUT_H

#include "SingleTriggerInput.h"

#include <cstdint>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

class OfflinePacket;
class Packet;
class PHCompositeNode;

class SingleZdcTriggerInput : public SingleTriggerInput
{
 public:
  explicit SingleZdcTriggerInput(const std::string &name);
  ~SingleZdcTriggerInput() override;
  void FillPool(const unsigned int keep) override;
  void CleanupUsedPackets(const int eventno) override;
  void ClearCurrentEvent() override;
  bool GetSomeMoreEvents(const unsigned int keep);
  void Print(const std::string &what = "ALL") const override;
  void CreateDSTNode(PHCompositeNode *topNode) override;

 private:
  Packet **plist{nullptr};

  std::set<int> m_EventNumber;
  std::set<int> m_EventStack;
};

#endif
