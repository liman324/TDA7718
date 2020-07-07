#include <TDA7718.h>

TDA7718 tda;

void setup(){
  audio();
  }
void loop(){}

void audio(){
       tda.setMain(0,0,0,0); // 0,0,0,0
 // main_sel  - 0 SE1 / 1 SE3 / 2 QD1 / 3 QD2_FD1 / 4 SE2 / 5 SE4 / 6 SE5 / 7 MUTE === TDA7718N
 // main_sel  - 0 SE1 / 1 SE3 / 2 QD1 / 3 QD2_FD1 / 4 SE2 / 5 MUTE / 6 MUTE / 7 MUTE === TDA7718B
 // fd_qd - 0 FD / 1 QD2 
 // main_gain - 0 0dB / 1 3dB
 // sub_flat -  0 off / 1 on
        tda.setSoft_mute(0,0,1,0,0,0,0);// 0,0,1,0,0,0,0
 // soft_mute -  0 off / 1 on
 // pin_iic - 0 pin_and_iic / 1 iic 
 // soft_mute_time - 0 0.48ms / 1 0.96ms / 2 7.68ms / 3 15.63ms
 // sub_in - 0 input_mux / 1 bass_output  
 // sub_eneble - 0 on / 1 off
 // fast_ch - 0 on / 1 off
 // anty_filter - 0 on / off(bypass)
        tda.setSoft_step_1(0,0,0,0,0,0,0,0); // 0,0,0,0,0,0,0,0
 // all - 0 on / 1 off
        tda.setSoft_step_2(0,0,0,0,1,1); // 0,0,0,0,1,1
 // rr_soft -  0 on / 1 off
 // sub_l_soft -  0 on / 1 off
 // sub_r_soft -  0 on / 1 off
 // soft_time - 0 5ms / 1 10ms
 // zero - 0 100mV / 1 75mV / 2 50mV / 3 25mV
 // spike - 0 11mkS / 1 22mkS / 2 33mkS / 3 44mkS
        tda.setLoudness(0,0,0,0); // 0,0,0,0
 // lon_att - byte 0...15 = 0...-15dB 
 // lon_cen_f - 0 flat / 1 400Hz / 2 800Hz / 3 2400Hz
 // lon_h_boost - 0 on / 1 off
 // lon_soft_step - 0 act / 1 wait
        tda.setVolume_gain(0,0,0); // 0,0,0
 // vol_gain - int -31...23 = -31...+23dB
 // vol_out_gain - 0 1dB / 1 0dB
 // vol_soft_step - 0 act / 1 wait
        tda.setTreble(0,0,0); // 0,0,0
 // treb - int -15...+15 = -15...+15dB 
 // treb_cen_f - 0 10.0kHz / 1 12.5kHz / 2 15.0kHz / 3 17.5 kHz
 // treb_soft_step - 0 act / 1 wait
        tda.setMiddle(0,0,0); // 0,0,0
 // mid - int -15...+15 = -15...+15dB 
 // mid_q - 0 0.75 / 1 1.0 / 2 1.25 / 3 reserved 
 // mid_soft_step - 0 act / 1 wait
        tda.setBass(0,0,0); // 0,0,0
 // bass - int -15...+15 = -15...+15dB 
 // bass_q - 0 1.0 / 1 1.25 / 2 1.5 / 3 2.0 
 // bass_soft_step - 0 act / 1 wait
        tda.setSub_Mid_Bass(0,0,0,0,0); // 0,0,0,0,0
 // sub_cen_f - 0 55Hz / 1 85Hz / 2 120Hz / 3 160Hz
 // sub_faza - 0 180deg / 1 0deg
 // mid_cen_f - 0 500Hz / 1 1000Hz / 2 1500Hz / 3 2500Hz
 // bass_cen_f - 0 60Hz / 1 80Hz / 2 100Hz / 3 200Hz
 // bass_dc - 0 on / 1 off
        tda.setLF(0,0);
        tda.setRF(0,0);
        tda.setLR(0,0);
        tda.setRR(0,0);
        tda.setSL(0,0);
        tda.setSR(0,0);
 // all int -79...+15 = -79...+15dB
 // all - 0 act / 1 wait
  }
