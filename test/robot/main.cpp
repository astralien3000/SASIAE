#include <aversive.hpp>

#include <base/integer.hpp>

#include <system/scheduler.hpp>

#include <device/eirbot2014/motor.hpp>
#include <device/eirbot2014/encoder.hpp>

//#include <device/stream/uart_stream.hpp>

s32 MOT_L = 0;
s32 MOT_R = 0;

s32 ENC_L = 0;
s32 ENC_R = 0;

Motor<s32> mot_l("left_motor", &MOT_L), mot_r("right_motor", &MOT_R);
Encoder<s32> enc_l("left_encoder", &ENC_L), enc_r("right_encoder", &ENC_R);  

//UartStream<0> io("stdio");

Scheduler& sched = Scheduler::instance();

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  
  Task t1([]() {
      if(enc_l.getValue() >= 10000 && MOT_L >= 0) {
	mot_l.setValue(-10);
	//io << "stop left !\n";
	//Aversive::stop();
      }
      if(enc_r.getValue() >= 50000 && MOT_R >= 0) {
	mot_r.setValue(-10);
	//io << "stop right !\n";
      }
      //ClientThread::instance().sendMessage(ClientThread::INFO, "TEST");
      
    });
  t1.setPeriod(10000);
  t1.setRepeat();

  sched.addTask(t1);

  mot_l.setValue(100);
  mot_r.setValue(100);

  while(Aversive::isRunning()) {
    Aversive::sleep();
    //io << "test " << ENC_L << " " << ENC_R << "\n";
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
