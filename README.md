# CMS Open Data analysis using Kubernetes

## Description

Nowadays anyone can get access to computing resources via public cloud vendors. This example will give you a way of running realistic physics analyses “in the cloud” using Kubernetes.

## Usage instrucctions

1. Go to [Google Cloud Platform](https://console.cloud.google.com/).
2. Create your cluster (in this example, our cluster name is "cluster-1" and We use 5 nodes of 16 Gb).
3. Enter the cloud shell and execute:
```
gcloud auth login

```
4. Connect to cluster and copy all the files in this repository.

5. Install argo as a workflow engine:
```
kubectl create ns argo
kubectl apply -n argo -f https://raw.githubusercontent.com/argoproj/argo/stable/manifests/quick-start-postgres.yaml
curl -sLO https://github.com/argoproj/argo/releases/download/v2.11.1/argo-linux-amd64.gz
gunzip argo-linux-amd64.gz
chmod +x argo-linux-amd64
sudo mv ./argo-linux-amd64 /usr/local/bin/argo
```
6. You need to execute the following command so that the argo workflow controller has sufficient rights to manage the workflow pods.
```
kubectl create clusterrolebinding YOURNAME-cluster-admin-binding --clusterrole=cluster-admin --user=YOURMAIL
```
7. Check that argo is available:
```
argo version
```
8. We need to apply a small patch to the default argo config.
```
kubectl patch configmap workflow-controller-configmap -n argo --patch "$(cat patch-workflow-controller-configmap.yaml)"
```
9. You can change the default namespace to argo as follows:
```
kubectl config set-context --current --namespace=argo
```
10. Defining a storage volume to store workflow output on Google Kubernetes Engine:
```
gcloud compute disks create --size=100GB --zone=us-central1-c gce-nfs-disk-1

```
11. Create the PersistentVolume and the PersistentVolumeClaim:
```
kubectl apply -n argo -f 001-nfs-server.yaml
kubectl apply -n argo -f 002-nfs-server-service.yaml
kubectl apply -n argo -f 003-pv-pvc.yaml
```
##### Before applying the third file, you must modify the argument of the "server" line with the IP of your cluster, you can obtain it with the command:
```
kubectl get -n argo svc nfs-server |grep ClusterIP | awk '{ print $3; }'
```
12. Now you can submit your workflow:
```
argo submit -n argo argo-wf-cms.yaml
```
13. Check that your workflow is runing:
```
argo get @latest
```
14. Once the workflow is done, we can get the outputs defining a container, a “storage pod” and mount the volume there so that we can get access to it.
```
kubectl apply -f pv-pod.yaml -n argo
```
15. To copy the files from that volume to the cloud shell:
```
kubectl cp  pv-pod:/mnt/data poddata -n argo
```


##### As a result you will get the files created by the workflow in /poddata/
