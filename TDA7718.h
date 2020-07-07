#ifndef TDA7718_H
#define TDA7718_H

#define TDA7718_address 0b1000100 // 7 bit

#define MAIN            0b00000000
#define SOFT_MUTE       0b00000100
#define SOFT_STEP1      0b00000101
#define SOFT_STEP2      0b00000110
#define LOUNNESS        0b00000111
#define VOLUME_OUT      0b00001000
#define TERBLE          0b00001001
#define MIDDLE          0b00001010
#define BASS            0b00001011
#define SUB_MID_BASS    0b00001100
#define ATT_LF          0b00001101
#define ATT_RF          0b00001110
#define ATT_LR          0b00001111
#define ATT_RR          0b00010000
#define ATT_SL          0b00010001
#define ATT_SR          0b00010010

#include <Arduino.h>
class TDA7718
{
  public:
    TDA7718();
	void setMain(byte main_sel, byte fd_qd, byte main_gain, byte sub_flat); // 0,0,0,0
 // main_sel  - 0 SE1 / 1 SE3 / 2 QD1 / 3 QD2_FD1 / 4 SE2 / 5 SE4 / 6 SE5 / 7 MUTE === TDA7718N
 // main_sel  - 0 SE1 / 1 SE3 / 2 QD1 / 3 QD2_FD1 / 4 SE2 / 5 MUTE / 6 MUTE / 7 MUTE === TDA7718B
 // fd_qd - 0 FD / 1 QD2 
 // main_gain - 0 0dB / 1 3dB
 // sub_flat -  0 off / 1 on
        void setSoft_mute(byte soft_mute, byte pin_iic, byte soft_mute_time, byte sub_in, byte sub_eneble, byte fast_ch, byte anty_filter);// 0,0,1,0,0,0,0
 // soft_mute -  0 off / 1 on
 // pin_iic - 0 pin_and_iic / 1 iic 
 // soft_mute_time - 0 0.48ms / 1 0.96ms / 2 7.68ms / 3 15.63ms
 // sub_in - 0 input_mux / 1 bass_output  
 // sub_eneble - 0 on / 1 off
 // fast_ch - 0 on / 1 off
 // anty_filter - 0 on / off(bypass)
        void setSoft_step_1(byte loud_soft, byte vol_soft, byte treb_soft, byte mid_soft, byte bass_soft, byte lf_soft, byte rf_soft, byte lr_soft); // 0,0,0,0,0,0,0,0
 // all - 0 on / 1 off
        void setSoft_step_2(byte rr_soft, byte sub_l_soft, byte sub_r_soft, byte soft_time, byte zero, byte spike); // 0,0,0,0,1,1
 // rr_soft -  0 on / 1 off
 // sub_l_soft -  0 on / 1 off
 // sub_r_soft -  0 on / 1 off
 // soft_time - 0 5ms / 1 10ms
 // zero - 0 100mV / 1 75mV / 2 50mV / 3 25mV
 // spike - 0 11mkS / 1 22mkS / 2 33mkS / 3 44mkS
        void setLoudness(byte lon_att, byte lon_cen_f, byte lon_h_boost, byte lon_soft_step); // 0,0,0,0
 // lon_att - byte 0...15 = 0...-15dB 
 // lon_cen_f - 0 flat / 1 400Hz / 2 800Hz / 3 2400Hz
 // lon_h_boost - 0 on / 1 off
 // lon_soft_step - 0 act / 1 wait
        void setVolume_gain(int vol_gain, byte vol_out_gain, byte vol_soft_step); // 0,0,0
 // vol_gain - int -31...23 = -31...+23dB
 // vol_out_gain - 0 1dB / 1 0dB
 // vol_soft_step - 0 act / 1 wait
        void setTreble(int treb, byte treb_cen_f, byte treb_soft_step); // 0,0,0
 // treb - int -15...+15 = -15...+15dB 
 // treb_cen_f - 0 10.0kHz / 1 12.5kHz / 2 15.0kHz / 3 17.5 kHz
 // treb_soft_step - 0 act / 1 wait
        void setMiddle(int mid, byte mid_q, byte mid_soft_step); // 0,0,0
 // mid - int -15...+15 = -15...+15dB 
 // mid_q - 0 0.75 / 1 1.0 / 2 1.25 / 3 reserved 
 // mid_soft_step - 0 act / 1 wait
        void setBass(int bass, byte bass_q, byte bass_soft_step); // 0,0,0
 // bass - int -15...+15 = -15...+15dB 
 // bass_q - 0 1.0 / 1 1.25 / 2 1.5 / 3 2.0 
 // bass_soft_step - 0 act / 1 wait
        void setSub_Mid_Bass(byte sub_cen_f, byte sub_faza, byte mid_cen_f, byte bass_cen_f, byte bass_dc);
 // sub_cen_f - 0 55Hz / 1 85Hz / 2 120Hz / 3 160Hz
 // sub_faza - 0 180deg / 1 0deg
 // mid_cen_f - 0 500Hz / 1 1000Hz / 2 1500Hz / 3 2500Hz
 // bass_cen_f - 0 60Hz / 1 80Hz / 2 100Hz / 3 200Hz
 // bass_dc - 0 on / 1 off
        void setLF(int lf, byte lf_soft_step);
        void setRF(int rf, byte rf_soft_step);
        void setLR(int lr, byte lr_soft_step);
        void setRR(int rr, byte rr_soft_step);
        void setSL(int sl, byte sl_soft_step);
        void setSR(int sr, byte sr_soft_step);
 // all int -79...+15 = -79...+15dB
 // all - 0 act / 1 wait


  private:
	void writeWire(char a, char b);
};
	
#endif //TDA7718_H
