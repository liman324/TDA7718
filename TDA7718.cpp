#include <Arduino.h>
#include <Wire.h>
#include "TDA7718.h"

TDA7718::TDA7718(){
	Wire.begin();
}



void TDA7718::setMain(byte main_sel, byte fd_qd, byte main_gain, byte sub_flat){
        switch(main_sel){
           case 0: main_sel = 0b00000000;break; 
           case 1: main_sel = 0b00000001;break;
           case 2: main_sel = 0b00000010;break;
           case 3: main_sel = 0b00000011;break;
           case 4: main_sel = 0b00000100;break;
           case 5: main_sel = 0b00000101;break;
           case 6: main_sel = 0b00000110;break;
           case 7: main_sel = 0b00000111;break;
}
        switch(fd_qd){
           case 0: fd_qd = 0b00000000;break; 
           case 1: fd_qd = 0b00001000;break;
}
        switch(main_gain){
           case 0: main_gain = 0b00000000;break; 
           case 1: main_gain = 0b00010000;break;
}
        switch(sub_flat){
           case 0: sub_flat = 0b00000000;break; 
           case 1: sub_flat = 0b00100000;break;
}
   writeWire(MAIN, main_sel + fd_qd + main_gain + sub_flat);	
}


void TDA7718::setSoft_mute(byte soft_mute, byte pin_iic, byte soft_mute_time, byte sub_in, byte sub_eneble, byte fast_ch, byte anty_filter){
        switch(soft_mute){
           case 0: soft_mute = 0b00000000;break; 
           case 1: soft_mute = 0b00000001;break;      
}
        switch(pin_iic){
           case 0: pin_iic = 0b00000000;break; 
           case 1: pin_iic = 0b00000010;break;      
}
        switch(soft_mute_time){
           case 0: soft_mute_time = 0b00000000;break; 
           case 1: soft_mute_time = 0b00000100;break;
           case 2: soft_mute_time = 0b00001000;break;
           case 3: soft_mute_time = 0b00001100;break;      
}
        switch(sub_in){
           case 0: sub_in = 0b00000000;break; 
           case 1: sub_in = 0b00010000;break;      
}
        switch(sub_eneble){
           case 0: sub_eneble = 0b00000000;break; 
           case 1: sub_eneble = 0b00100000;break;      
}
      switch(fast_ch){
           case 0: fast_ch = 0b00000000;break; 
           case 1: fast_ch = 0b01000000;break;      
}
      switch(anty_filter){
           case 0: anty_filter = 0b00000000;break; 
           case 1: anty_filter = 0b10000000;break;      
}
   
   writeWire(SOFT_MUTE, soft_mute + pin_iic + soft_mute_time + sub_in + sub_eneble + fast_ch + anty_filter);	
}
         
void TDA7718::setSoft_step_1(byte loud_soft, byte vol_soft, byte treb_soft, byte mid_soft, byte bass_soft, byte lf_soft, byte rf_soft, byte lr_soft){
        switch(loud_soft){
           case 0: loud_soft = 0b00000000;break; 
           case 1: loud_soft = 0b00000001;break;      
}
        switch(vol_soft){
           case 0: vol_soft = 0b00000000;break; 
           case 1: vol_soft = 0b00000010;break;      
}
        switch(treb_soft){
           case 0: treb_soft = 0b00000000;break; 
           case 1: treb_soft = 0b00000100;break;      
}
        switch(mid_soft){
           case 0: mid_soft = 0b00000000;break; 
           case 1: mid_soft = 0b00001000;break;      
}
        switch(bass_soft){
           case 0: bass_soft = 0b00000000;break; 
           case 1: bass_soft = 0b00010000;break;      
}
        switch(lf_soft){
           case 0: lf_soft = 0b00000000;break; 
           case 1: lf_soft = 0b00100000;break;      
}
        switch(rf_soft){
           case 0: rf_soft = 0b00000000;break; 
           case 1: rf_soft = 0b01000000;break;      
}
        switch(lr_soft){
           case 0: lr_soft = 0b00000000;break; 
           case 1: lr_soft = 0b10000000;break;      
}
   writeWire(SOFT_STEP1, loud_soft + vol_soft + treb_soft + mid_soft + bass_soft + lf_soft + rf_soft + lr_soft);	
}


void TDA7718::setSoft_step_2(byte rr_soft, byte sub_l_soft, byte sub_r_soft, byte soft_time, byte zero, byte spike){
        switch(rr_soft){
           case 0: rr_soft = 0b00000000;break; 
           case 1: rr_soft = 0b00000001;break;      
}
        switch(sub_l_soft){
           case 0: sub_l_soft = 0b00000000;break; 
           case 1: sub_l_soft= 0b00000010;break;      
}
        switch(sub_r_soft){
           case 0: sub_r_soft = 0b00000000;break; 
           case 1: sub_r_soft = 0b00000100;break;      
}
        switch(soft_time){
           case 0: soft_time = 0b00000000;break; 
           case 1: soft_time = 0b00001000;break;      
}
        switch(zero){
           case 0: zero = 0b00000000;break; 
           case 1: zero = 0b00010000;break;
           case 2: zero = 0b00100000;break; 
           case 3: zero = 0b00110000;break;      
}
        switch(spike){
           case 0: spike = 0b00000000;break; 
           case 1: spike = 0b01000000;break;
           case 2: spike = 0b10000000;break; 
           case 3: spike = 0b11000000;break;      
}
   writeWire(SOFT_STEP2, rr_soft + sub_l_soft + sub_r_soft + soft_time + zero + spike);
}

void TDA7718::setLoudness(byte lon_att, byte lon_cen_f, byte lon_h_boost, byte lon_soft_step){
        switch(lon_cen_f){
           case 0: lon_cen_f = 0b00000000;break; 
           case 1: lon_cen_f = 0b00010000;break;
           case 2: lon_cen_f = 0b00100000;break; 
           case 3: lon_cen_f = 0b00110000;break;      
}
        switch(lon_h_boost){
           case 0: lon_h_boost = 0b00000000;break; 
           case 1: lon_h_boost = 0b01000000;break;
}
        switch(lon_soft_step){
           case 0: lon_soft_step = 0b00000000;break; 
           case 1: lon_soft_step = 0b10000000;break;
}
   writeWire(LOUNNESS, lon_att + lon_cen_f + lon_h_boost + lon_soft_step);
}

void TDA7718::setVolume_gain(int vol_gain, byte vol_out_gain, byte vol_soft_step){
          if(vol_gain<0){vol_gain = abs(vol_gain)+32;}
        switch(vol_out_gain){
           case 0: vol_out_gain = 0b00000000;break; 
           case 1: vol_out_gain = 0b01000000;break;
}
        switch(vol_soft_step){
           case 0: vol_soft_step = 0b00000000;break; 
           case 1: vol_soft_step = 0b10000000;break;
}
   writeWire(VOLUME_OUT, vol_gain + vol_out_gain + vol_soft_step);
}

void TDA7718::setTreble(int treb, byte treb_cen_f, byte treb_soft_step){
        if(treb >= 0){treb = 31 - treb;}
        if(treb < 0){treb = treb + 15;}
        switch(treb_cen_f){
           case 0: treb_cen_f = 0b00000000;break; 
           case 1: treb_cen_f = 0b00100000;break;
           case 2: treb_cen_f = 0b01000000;break; 
           case 3: treb_cen_f = 0b01100000;break;      
}
        switch(treb_soft_step){
           case 0: treb_soft_step = 0b00000000;break; 
           case 1: treb_soft_step = 0b10000000;break;
}
    writeWire(TERBLE, treb + treb_cen_f + treb_soft_step);
}

void TDA7718::setMiddle(int mid, byte mid_q, byte mid_soft_step){
        if(mid >= 0){mid = 31 - mid;}
        if(mid < 0){mid = mid + 15;}
        switch(mid_q){
           case 0: mid_q = 0b00000000;break; 
           case 1: mid_q = 0b00100000;break;
           case 2: mid_q = 0b01000000;break; 
           case 3: mid_q = 0b01100000;break;      
}
        switch(mid_soft_step){
           case 0: mid_soft_step = 0b00000000;break; 
           case 1: mid_soft_step = 0b10000000;break;
}
    writeWire(MIDDLE, mid + mid_q + mid_soft_step);
}

void TDA7718::setBass(int bass, byte bass_q, byte bass_soft_step){
        if(bass >= 0){bass = 31 - bass;}
        if(bass < 0){bass = bass + 15;}
        switch(bass_q){
           case 0: bass_q = 0b00000000;break; 
           case 1: bass_q = 0b00100000;break;
           case 2: bass_q = 0b01000000;break; 
           case 3: bass_q = 0b01100000;break;      
}
        switch(bass_soft_step){
           case 0: bass_soft_step = 0b00000000;break; 
           case 1: bass_soft_step = 0b10000000;break;
}
    writeWire(BASS, bass + bass_q + bass_soft_step);
}


void TDA7718::setSub_Mid_Bass(byte sub_cen_f, byte sub_faza, byte mid_cen_f, byte bass_cen_f, byte bass_dc){
        switch(sub_cen_f){
           case 0: sub_cen_f = 0b00000000;break; 
           case 1: sub_cen_f = 0b00000001;break;
           case 2: sub_cen_f = 0b00000010;break; 
           case 3: sub_cen_f = 0b00000011;break;      
}
        switch(sub_faza){
           case 0: sub_faza = 0b00000000;break; 
           case 1: sub_faza = 0b00000100;break;
}
        switch(mid_cen_f){
           case 0: mid_cen_f = 0b00000000;break; 
           case 1: mid_cen_f = 0b00001000;break;
           case 2: mid_cen_f = 0b00010000;break; 
           case 3: mid_cen_f = 0b00011000;break;      
}
        switch(bass_cen_f){
           case 0: bass_cen_f = 0b00000000;break; 
           case 1: bass_cen_f = 0b00100000;break;
           case 2: bass_cen_f = 0b01000000;break; 
           case 3: bass_cen_f = 0b01100000;break;      
}
        switch(bass_dc){
           case 0: bass_dc = 0b00000000;break; 
           case 1: bass_dc = 0b10000000;break;
}
    writeWire(SUB_MID_BASS, sub_cen_f + sub_faza + mid_cen_f + bass_cen_f + bass_dc);
}


void TDA7718::setLF(int lf, byte lf_soft_step){
            if(lf < 0){lf = abs(lf) + 16;}
            writeWire(ATT_LF, lf + (lf_soft_step << 7)); 
}

void TDA7718::setRF(int rf, byte rf_soft_step){
            if(rf < 0){rf = abs(rf) + 16;}
            writeWire(ATT_RF, rf + (rf_soft_step << 7)); 
}

void TDA7718::setLR(int lr, byte lr_soft_step){
            if(lr < 0){lr = abs(lr) + 16;}
            writeWire(ATT_LR, lr + (lr_soft_step << 7)); 
}

void TDA7718::setRR(int rr, byte rr_soft_step){
            if(rr < 0){rr = abs(rr) + 16;}
            writeWire(ATT_RR, rr + (rr_soft_step << 7)); 
}

void TDA7718::setSL(int sl, byte sl_soft_step){
            if(sl < 0){sl = abs(sl) + 16;}
            writeWire(ATT_SL, sl + (sl_soft_step << 7)); 
}

void TDA7718::setSR(int sr, byte sr_soft_step){
            if(sr < 0){sr = abs(sr) + 16;}
            writeWire(ATT_SR, sr + (sr_soft_step << 7)); 
}



void TDA7718::writeWire(char a, char b){
  Wire.beginTransmission(TDA7718_address);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
