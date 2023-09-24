import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import datetime as dt
import yfinance as yf
yf.pdr_override()
from pandas_datareader import data as pdr

#Functions block, we define all the functions that we need

def getData(stock,startDate,endDate):
    stockData = pdr.get_data_yahoo(stock,start = startDate,end = endDate)
    #saving the data to CSV's files
    saveDataToCSV(stockData,stock)
    return stockData

def saveDataToCSV(data,fileName):
    data.to_csv('./output/'+fileName+'.csv')

def plotData(stockData, ticker):
    stockData = stockData.reset_index()
    dates = list(stockData['Date'])
    close = list(stockData['Close'])

    plt.figure(figsize=(10,6))
    plt.plot(dates,close)
    plt.xlabel('Date')
    plt.ylabel('Closing Price in EUR')
    plt.title(ticker + " Stock Price")
    plt.show()


#In this Block we retrieve data specified by the user in the stockList array
#we store the data in an array called 'data' for future purposes (plotting)
#we also store the data in different CSV files

stockList = ['AAPL','TSLA','UCG.MI']
endDate = dt.datetime.now()
startDate = endDate - dt.timedelta(days = 10) #select for how many days you want to retrieve data

data = [] #array used to store all of different stocks data

for ticker in stockList:
    data.append(getData(ticker,startDate,endDate))


#plotting block, we decide whether to plot or not

'''

i = 0
for ticker in stockList:
    plotData(data[i],ticker)
    i+=1

'''