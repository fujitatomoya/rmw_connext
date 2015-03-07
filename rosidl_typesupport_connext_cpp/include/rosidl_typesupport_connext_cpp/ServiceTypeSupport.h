
#ifndef __rmw_connext_cpp__ServiceTypeSupport__h__
#define __rmw_connext_cpp__ServiceTypeSupport__h__

#include <rmw/rmw.h>
#include "rosidl_generator_cpp/ServiceTypeSupport.h"

class DDSDomainParticipant;
class DDSDataReader;
struct DDS_SampleIdentity_t;

namespace rmw
{

extern const char * _rti_connext_identifier;

}  // namespace rmw

namespace rmw_connext_cpp
{

typedef struct ServiceTypeSupportCallbacks {
  const char * _package_name;
  const char * _message_name;
  void* (*_create_requester)(DDSDomainParticipant * participant, const char * service_name, DDSDataReader **reader);
  void* (*_create_replier)(DDSDomainParticipant * participant, const char * service_name, DDSDataReader **reader);
  int64_t (*_send_request)(void * requester, const void * ros_request);
  ::rmw::ROS2_RETCODE_t (*_receive_response)(void * requester, void * ros_response);
  bool (*_take_request)(void * replier, void * ros_request, void * ros_request_header);
  void (*_send_response)(void * replier, const void * ros_request, const void * ros_response);
  bool (*_take_response)(void * requester, void * ros_response, void * ros_request_header);
} ServiceTypeSupportCallbacks;

template<typename T>
const rosidl_generator_cpp::ServiceTypeSupportHandle& get_service_type_support_handle();

}  // namespace rmw_connext_cpp

#endif  // __rmw_connext_cpp__ServiceTypeSupport__h__