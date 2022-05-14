#!/usr/bin/env python
# coding: utf-8

# In[1]:


import os
import numpy as np
import folium
import shapely.wkt
import geopandas
import matplotlib.pyplot as plt
from osgeo import ogr, osr, gdal

version_num = int(gdal.VersionInfo('VERSION_NUM'))
print(version_num)


# In[2]:


import ogr
cnt = ogr.GetDriverCount()
formatsList = []

for i in range(cnt):
    driver = ogr.GetDriver(i)
    driverName = driver.GetName()
    if not driverName in formatsList:
        formatsList.append(driverName)

formatsList.sort() 

for i in formatsList:
    print (i)


# Nie wiem czemu, ale stosujac też inne metody dla ogr2ogr zawsze returncode wynosi 1 co oznacza blad, natomiast jedyny inny efekt jaki uzyskale to returncode 3221225781, co tez było wartoscia bledna

# In[3]:


from osgeo import gdal
import subprocess
import os

path= "C:/Program Files/QGIS 3.16/bin/"
ogr2ogr = "ogr2ogr.exe"
gdalwarp="gdalwarp.exe"
src = "C:\\Users\JaSzw\OneDrive\Pulpit\Geoinfa\lab10_ogr_wektor 2\budynki.shp"
dst = "C:\\Users\JaSzw\OneDrive\Pulpit\Geoinfa\lab10_ogr_wektor 2\budynki.gpkg"
options=" -s_srs EPSG:2180 -t_srs EPSG:2180 -f GPKG "

subprocess.run(path + ogr2ogr + options + dst + " " + src)

#subprocess.call(["ogr2ogr", "-f", "GPKG", dst, src], shell=True)


# In[4]:


dst2 = "C:\\Users\JaSzw\OneDrive\Pulpit\Geoinfa\lab10_ogr_wektor 2\budynkikml"
options2=" -s_srs EPSG:2180 -t_srs EPSG:4326 -f KML "
subprocess.run(path + ogr2ogr + options2 + dst2 + " " + src)


# In[5]:


dst3 = "C:\\Users\JaSzw\OneDrive\Pulpit\Geoinfa\lab10_ogr_wektor 2\budynki.json"
options3=" -s_srs EPSG:2180 -t_srs EPSG:2176 -f GeoJSON "
subprocess.run(path + ogr2ogr + options3 + dst3 + " " + src)


# In[6]:


path=r"C:\\Users\JaSzw\OneDrive\Pulpit\Geoinfa\lab10_ogr_wektor 2"
file="budynki.shp"
budynki_tr=os.path.join(path,file)
budynki_gdf = geopandas.read_file(budynki_tr)
budynki_gdf_1=budynki_gdf
budynki_gdf_2=budynki_gdf
budynki_gdf_3=budynki_gdf
budynki_gdf_2.crs="EPSG:4326"
budynki_gdf_3.crs="EPSG:2176"


# In[7]:


#budynki_gdf_1.to_file("budynki_g.gpkg", driver="GPKG")


# In[8]:


#budynki_gdf_2.to_file("budynki.kml", driver='KML' )
budynki_gdf_3.to_file("budynki_j.json", driver='GeoJSON')


# In[9]:


driver = ogr.GetDriverByName('ESRI Shapefile')
dataset = driver.Open(r'C:\\Users\JaSzw\OneDrive\Pulpit\Geoinfa\lab10_ogr_wektor 2\budynki.shp')


layer = dataset.GetLayer()
spatialRef = layer.GetSpatialRef()

feature = layer.GetNextFeature()
geom = feature.GetGeometryRef()
spatialRef = geom.GetSpatialReference()
print (spatialRef)


# In[ ]:




