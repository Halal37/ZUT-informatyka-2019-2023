import cv2
import numpy as np
import tests as tst

if __name__== '__main__':
    f=open('test_message.txt','r')
    img_cat = cv2.imread('MicrosoftTeams-image (9).png')
    img_yin = cv2.imread('MicrosoftTeams-image (8).png')

    text = f.read()
    text = bytes(text,'utf-8')
    text = np.frombuffer(text,dtype=np.uint8)

    #tst.waterMarkTests(img_cat,img_yin,alpha=1.0)
    orig_layer_r, r =tst.steganographyTestsImage(img_cat,img_yin,bits=3,layer="r")
    orig_layer_g, g=tst.steganographyTestsImage(img_cat,img_yin,bits=3,layer="g")
    orig_layer_b, b=tst.steganographyTestsImage(img_cat,img_yin,bits=7,layer="b")  
    tst.steganographyPlotLayer(orig_layer_r,r,"r",64)
    tst.steganographyAppendAndPlotLayers(img_cat,img_yin,r,g,b,3,3,7)
    tst.steganographyTestsText(img_cat,text,bits=2,layer="r")
    f.close()  
