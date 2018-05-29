// Auto-generated. Do not edit!

// (in-package ferns_detector.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let DetectedPoint = require('./DetectedPoint.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Detection {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.model = null;
      this.top_left = null;
      this.top_right = null;
      this.bottom_right = null;
      this.bottom_left = null;
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
      if (initObj.hasOwnProperty('top_left')) {
        this.top_left = initObj.top_left
      }
      else {
        this.top_left = new DetectedPoint();
      }
      if (initObj.hasOwnProperty('top_right')) {
        this.top_right = initObj.top_right
      }
      else {
        this.top_right = new DetectedPoint();
      }
      if (initObj.hasOwnProperty('bottom_right')) {
        this.bottom_right = initObj.bottom_right
      }
      else {
        this.bottom_right = new DetectedPoint();
      }
      if (initObj.hasOwnProperty('bottom_left')) {
        this.bottom_left = initObj.bottom_left
      }
      else {
        this.bottom_left = new DetectedPoint();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Detection
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [model]
    bufferOffset = _serializer.string(obj.model, buffer, bufferOffset);
    // Serialize message field [top_left]
    bufferOffset = DetectedPoint.serialize(obj.top_left, buffer, bufferOffset);
    // Serialize message field [top_right]
    bufferOffset = DetectedPoint.serialize(obj.top_right, buffer, bufferOffset);
    // Serialize message field [bottom_right]
    bufferOffset = DetectedPoint.serialize(obj.bottom_right, buffer, bufferOffset);
    // Serialize message field [bottom_left]
    bufferOffset = DetectedPoint.serialize(obj.bottom_left, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Detection
    let len;
    let data = new Detection(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [model]
    data.model = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [top_left]
    data.top_left = DetectedPoint.deserialize(buffer, bufferOffset);
    // Deserialize message field [top_right]
    data.top_right = DetectedPoint.deserialize(buffer, bufferOffset);
    // Deserialize message field [bottom_right]
    data.bottom_right = DetectedPoint.deserialize(buffer, bufferOffset);
    // Deserialize message field [bottom_left]
    data.bottom_left = DetectedPoint.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += object.model.length;
    return length + 36;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ferns_detector/Detection';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '32608db182e57959f8cbb42d13b3f08c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header 								header
    string                              model
    DetectedPoint 						top_left
    DetectedPoint 						top_right
    DetectedPoint 						bottom_right
    DetectedPoint 						bottom_left
    
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
    
    ================================================================================
    MSG: ferns_detector/DetectedPoint
    int32 												  x
    int32 													y
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Detection(null);
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

    if (msg.top_left !== undefined) {
      resolved.top_left = DetectedPoint.Resolve(msg.top_left)
    }
    else {
      resolved.top_left = new DetectedPoint()
    }

    if (msg.top_right !== undefined) {
      resolved.top_right = DetectedPoint.Resolve(msg.top_right)
    }
    else {
      resolved.top_right = new DetectedPoint()
    }

    if (msg.bottom_right !== undefined) {
      resolved.bottom_right = DetectedPoint.Resolve(msg.bottom_right)
    }
    else {
      resolved.bottom_right = new DetectedPoint()
    }

    if (msg.bottom_left !== undefined) {
      resolved.bottom_left = DetectedPoint.Resolve(msg.bottom_left)
    }
    else {
      resolved.bottom_left = new DetectedPoint()
    }

    return resolved;
    }
};

module.exports = Detection;
