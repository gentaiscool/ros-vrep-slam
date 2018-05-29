// Auto-generated. Do not edit!

// (in-package ferns_detector.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ModelStatus {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.model = null;
      this.loaded = null;
      this.active = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('model')) {
        this.model = initObj.model
      }
      else {
        this.model = '';
      }
      if (initObj.hasOwnProperty('loaded')) {
        this.loaded = initObj.loaded
      }
      else {
        this.loaded = false;
      }
      if (initObj.hasOwnProperty('active')) {
        this.active = initObj.active
      }
      else {
        this.active = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ModelStatus
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [model]
    bufferOffset = _serializer.string(obj.model, buffer, bufferOffset);
    // Serialize message field [loaded]
    bufferOffset = _serializer.bool(obj.loaded, buffer, bufferOffset);
    // Serialize message field [active]
    bufferOffset = _serializer.bool(obj.active, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ModelStatus
    let len;
    let data = new ModelStatus(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [model]
    data.model = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [loaded]
    data.loaded = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [active]
    data.active = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += object.model.length;
    return length + 6;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ferns_detector/ModelStatus';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6f51fe3ba1a4dacfef45b8036b90a8d3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header 								header
    string                              model
    bool                             loaded
    bool                             active
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ModelStatus(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.model !== undefined) {
      resolved.model = msg.model;
    }
    else {
      resolved.model = ''
    }

    if (msg.loaded !== undefined) {
      resolved.loaded = msg.loaded;
    }
    else {
      resolved.loaded = false
    }

    if (msg.active !== undefined) {
      resolved.active = msg.active;
    }
    else {
      resolved.active = false
    }

    return resolved;
    }
};

module.exports = ModelStatus;
