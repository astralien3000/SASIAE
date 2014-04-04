TEMPLATE = subdirs
SUBDIRS = modules/motor_wheel.pro \
          modules/encoder.pro \
          modules/GP2.pro \
          modules/RDS.pro \
          modules/servo.pro \
          modules/digital_servo.pro \
          gui/gui.pro 
CONFIG += ordered
