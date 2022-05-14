#!/usr/bin/env python
# coding: utf-8

# In[24]:


import os
import fiona
import numpy as np
import pprint
import matplotlib.pyplot as plt
import geopandas as gpd
import pandas as pd
import json


# In[25]:


path=r"C:\Users\JaSzw\OneDrive\Pulpit\Geoinfa\3262_GML\PL.PZGiK.339.3262\BDOT10k" 
file="PL.PZGiK.339.3262__OT_BUBD_A.xml"
bud=os.path.join(path,file)
bud_gdf = gpd.read_file(bud)
bud_gdf.head()


# In[26]:


bud_gdf.plot()


# In[27]:


bud_gdf.crs


# In[28]:


bud_gdf_gj=bud_gdf.to_crs("EPSG:4326")
bud_gdf_gj.crs


# In[29]:


bud_gdf_sh=bud_gdf.to_crs("EPSG:3857")
bud_gdf_geopack=bud_gdf.to_crs("EPSG:32633")
bud_gdf_gml=bud_gdf.to_crs("EPSG:2176")
bud_gdf_gj.to_file('C:\\Users\JaSzw\OneDrive\Pulpit\Geoinfa\Wynik_1.geojson', driver='GeoJSON')
bud_gdf_sh.to_file('C:\\Users\JaSzw\OneDrive\Pulpit\Geoinfa\Wynik_1.shp', driver='ESRI Shapefile')
bud_gdf_geopack.to_file('C:\\Users\JaSzw\OneDrive\Pulpit\Geoinfa\Wynik_1.gpkg', driver='GPKG')
bud_gdf_gml.to_file('C:\\Users\JaSzw\OneDrive\Pulpit\Geoinfa\Wynik_1.gml', driver='GML')


# In[30]:


path=r"C:\Users\JaSzw\OneDrive\Pulpit\Geoinfa\3262_GML\PL.PZGiK.339.3262\BDOT10k" 
file6="SpecjalneObszaryOchronyPolygon.shp"
file7="powiaty.gpkg"
nat=os.path.join(path,file6)
powiaty=os.path.join(path,file7)
polygon = gpd.read_file(powiaty)
nat_gdf = gpd.read_file(nat)
nat_gdf.head()


# In[31]:


polygon.head()


# In[32]:


nat_gdf.plot()


# In[33]:


polygon.plot()


# In[34]:


powiaty_int = gpd.overlay(nat_gdf, polygon, how='intersection').to_crs("epsg:2180")
powiaty_int.plot()


# In[35]:


powiaty_int.head()


# In[36]:


d = {'iip_identy': powiaty_int['iip_identy'], 'rozmiar_nat': powiaty_int.area/1000000}


# In[37]:


df = pd.DataFrame(data=d)


# In[38]:


nowe=df.groupby(['iip_identy']).sum()


# In[39]:


join = polygon.merge(nowe, on=('iip_identy'),how='left')
join.head()


# In[40]:


join


# In[41]:


join.insert(2, "procent", (join['rozmiar_nat']/(join.area/1000000))*100)


# In[42]:


join


# In[43]:


koniec = {'id_powiat': join['iip_identy'],'nazwa_powiatu': join['jpt_nazwa_'], 'powierzchnia_powiatu': join.area/1000000,'procent_powierzchni_zajmowany_przez_natura_2000': join['procent'],'geometry': join['geometry'],}


# In[44]:


docsv = pd.DataFrame(data=koniec)


# In[45]:


docsv


# In[46]:


styl = dict(method='zip',
                        archive_name='out.csv')
docsv.to_csv('out.zip',index=False,sep='|', compression=styl)


# In[ ]:




