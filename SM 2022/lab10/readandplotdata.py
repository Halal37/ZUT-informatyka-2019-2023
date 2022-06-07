import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression


def calculateMeanScoresPerPerson(df):
    users = 0
    users_arr = np.zeros((10, 7))
    for i in range(2, 23, 3):
        users_arr[:, users] = df[df.columns[i:i + 3]].mean(axis=1)
        users += 1

    return users_arr


def calculateMeanScoresPerAll(df):
    return df[df.columns[2:23]].mean(axis=1)


def plotIDMOS(df, algorithmLabel=None):
    symbols = ['r*', 'g^', 'bv', 'yo', 'k.', 'cp', 'mP']
    column_labels = df[df.columns[0]]
    users = ["badany1", "badany2", "badany3", "badany4", "badany5", "badany6", "badany7"]
    plt.figure(figsize=(16, 12))
    plt.subplot(1, 3, 1)
    plt.title("Mos dla obrazów - wszystkie oceny")
    plt.xlabel('Obrazy')
    plt.ylabel('Oceny MOS')

    size = 2
    cols = np.zeros(30)
    column_labels_tmp = np.tile(column_labels, 3)
    print(column_labels_tmp)
    for i in range(7):
        step = 0
        for j in range(0, 30, 10):
            cols[j:j + 10] = df[df.columns[size + step]]
            step += 1

        plt.plot(column_labels_tmp, cols, symbols[i], label=users[i])
        size += 3

    plt.legend()

    plt.subplot(1, 3, 2)
    plt.title("Mos dla obrazów - zagregowane dla badanego")
    plt.xlabel('Obrazy')
    plt.ylabel('Oceny MOS')

    meansPerPerson = calculateMeanScoresPerPerson(df)
    for j in range(meansPerPerson.shape[1]):
        plt.plot(column_labels, meansPerPerson[:, j], symbols[j], label=users[j])

    plt.legend()

    plt.subplot(1, 3, 3)
    plt.title("Mos dla obrazów - zagregowane")
    plt.xlabel('Obrazy')
    plt.ylabel('Oceny MOS')
    meansPerAll = calculateMeanScoresPerAll(df)
    plt.plot(column_labels, meansPerAll, symbols[0])

    plt.tight_layout()
    plt.savefig("img" + str(algorithmLabel) + ".png")
    #plt.show()


def plotMeasureMOS(df, measure, measureLabel=None, algorithmLabel=None, image_num=None):
    symbols = ['r*', 'g^', 'bv', 'yo', 'k.', 'cp', 'mP']
    users = ["badany1", "badany2", "badany3", "badany4", "badany5", "badany6", "badany7"]
    model = LinearRegression()
    plt.figure(figsize=(16, 12))
    plt.subplot(1, 3, 1)
    plt.title("Mos dla obrazów - wszystkie oceny")
    plt.xlabel('Miara jakości')
    plt.ylabel('Oceny MOS')

    size = 2
    cols = np.zeros(30)
    column_labels_tmp = np.tile(measure, 3)
    for i in range(7):
        step = 0
        for j in range(0, 30, 10):
            cols[j:j + 10] = df[df.columns[size + step]]
            step += 1
        print("#######")
        print(column_labels_tmp)
        print("#######")
        print(cols)
        plt.plot(column_labels_tmp, cols, symbols[i], label=users[i])
        model.fit(column_labels_tmp.reshape(-1, 1), cols.reshape(-1, 1))
        size += 3

    pred_y = model.predict(np.array([min(measure), max(measure)]).reshape(-1, 1))
    plt.title("Miara jakości " + measureLabel + " dla kategorii " + str(algorithmLabel))
    plt.plot([min(measure), max(measure)], pred_y)
    plt.legend()

    plt.subplot(1, 3, 2)
    plt.title("Mos dla obrazów - zagregowane dla badanego")
    plt.xlabel('Miara jakości')
    plt.ylabel('Oceny MOS')

    meansPerPerson = calculateMeanScoresPerPerson(df)
    for j in range(meansPerPerson.shape[1]):
        plt.plot(measure, meansPerPerson[:, j], symbols[j], label=users[j])

    plt.title("Miara jakości " + measureLabel + " dla kategorii " + str(algorithmLabel))
    plt.plot([min(measure), max(measure)], pred_y)
    plt.legend()

    plt.subplot(1, 3, 3)
    plt.title("Mos dla obrazów - zagregowane")
    plt.xlabel('Miara jakości')
    plt.ylabel('Oceny MOS')

    meansPerAll = calculateMeanScoresPerAll(df)
    plt.plot(measure, meansPerAll, symbols[0])
    plt.title("Miara jakości " + measureLabel + " dla kategorii " + str(algorithmLabel))
    plt.plot([min(measure), max(measure)], pred_y)

    plt.savefig("img" + str(image_num) + "_" + str(measureLabel) + "_" + str(algorithmLabel) + ".png")
    #plt.show()


def plotCorrelationMOS(df, measures, algorithmLabel):
    labels_x_y = ["MOS", "MSE", "NMSE", "PSNR", "IF", "SSIM"]

    all_scores = np.array(df[df.columns[2:23]])
    all_scores = all_scores.flatten(order="F")
    plt.figure(figsize=(16, 12))
    # for i in range(len(measures)):
    #     measures[i] = np.tile(measures[i], 21).reshape(-1, 1)
    meanScoresAll = calculateMeanScoresPerAll(df)

    corr_matrix = np.vstack((meanScoresAll, *measures))
    print(corr_matrix)
    print(corr_matrix.shape)
    corr_matrix = np.corrcoef(corr_matrix).round(decimals=2)
    print("#####")
    print(corr_matrix)
    print(corr_matrix.shape)
    heatmap = plt.pcolor(corr_matrix)
    plt.colorbar(heatmap)
    plt.xticks(np.arange(corr_matrix.shape[1]) + 0.5, labels_x_y)
    plt.yticks(np.arange(corr_matrix.shape[0]) + 0.5, labels_x_y)

    for x in range(corr_matrix.shape[0]):
        for y in range(corr_matrix.shape[1]):
            plt.text(y+0.5, x+0.5, '%.4f' % corr_matrix[x, y], horizontalalignment='center', verticalalignment='center')
    #plt.xlabel(labels_x_y, rotation=90)
    #plt.ylabel(labels_x_y)

    plt.title("Wykres korelacji dla kategorii " + str(algorithmLabel))
    plt.savefig("imgCorrelation_" + str(algorithmLabel) + ".png")

    #plt.show()
