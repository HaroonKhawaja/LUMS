import streamlit as st
import pandas as pd
import os

st.title("Car Log Record")

csv_file = "car_logs.csv"

st.markdown("View Saved License Plate Logs")
if os.path.exists(csv_file):
    df = pd.read_csv(csv_file, header=None, names=["License Plate", "Timestamp", "Image File"])
    st.dataframe(df)
else:
    st.error("CSV file does not exist. Nothing to be displayed.")